#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <ifaddrs.h>
#include <arpa/inet.h>


#define PORT 8124
#define MAP_SIZE 20

typedef struct {
  int player1_x;
  int player1_y;
  int player2_x;
  int player2_y;
} GameState;

GameState game_state = {0, 0, 15, 15};

#define EMPTY '.'

void initialize_map(char map[MAP_SIZE][MAP_SIZE]) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      map[i][j] = EMPTY;
    }
  }
  map[game_state.player1_x][game_state.player1_y] = 'A';
  map[game_state.player2_x][game_state.player2_y] = 'B';
}

void update_game_state(char command) {
  switch (command) {
  case 'u':
    if (game_state.player1_x > 0) game_state.player1_x--;
    break;
  case 'd':
    if (game_state.player1_x < 19) game_state.player1_x++;
    break;
  case 'l':
    if (game_state.player1_y > 0) game_state.player1_y--;
    break;
  case 'r':
    if (game_state.player1_y < 19) game_state.player1_y++;
    break;
  }
  //and move player 2 one step towards player 1
  if (game_state.player2_x < game_state.player1_x) game_state.player2_x++;
  else if (game_state.player2_x > game_state.player1_x) game_state.player2_x--;
  else if (game_state.player2_y < game_state.player1_y) game_state.player2_y++;
  else if (game_state.player2_y > game_state.player1_y) game_state.player2_y--;
}
void handle_request(int new_socket) {
  char http_response[1024];
  char buffer[1024] = {0};
  read(new_socket, buffer, 1024);

  if (strstr(buffer, "GET /game_state") != NULL) {
    char map[MAP_SIZE][MAP_SIZE];
    initialize_map(map);

    sprintf(http_response,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "\r\n");

    for (int i = 0; i < MAP_SIZE; i++) {
      for (int j = 0; j < MAP_SIZE; j++) {
        sprintf(http_response + strlen(http_response), "%c ", map[i][j]);
      }
      sprintf(http_response + strlen(http_response), "\n");
    }

    send(new_socket, http_response, strlen(http_response), 0);
  } else if (strstr(buffer, "POST /command") != NULL) {
    char *command = strstr(buffer, "\r\n\r\n") + 4;
    update_game_state(*command);
    sprintf(http_response,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "\r\n"
            "Command received: %c", *command);

    send(new_socket, http_response, strlen(http_response), 0);
  } else {
    sprintf(http_response,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "\r\n"
            "<!DOCTYPE html>\r\n"
            "<html>\r\n"
            "<head>\r\n"
            "<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js\"></script>\r\n"
            "<script>\r\n"
            "$(document).ready(function(){\r\n"
            "    setInterval(function(){\r\n"
            "        $.get('game_state', function(data, status){\r\n"
            "           $('#game_state').html('<pre>' + data + '</pre>')\r\n"
            "})\r\n"
            "    }, 1000);\r\n"
            "});\r\n"
            "$(document).keydown(function(e) {\r\n"
            "var command\r\n"
            "if (e.key == 'ArrowUp') command = 'u'\r\n"
            "else if (e.key == 'ArrowDown') command = 'd'\r\n"
            "else if (e.key == 'ArrowLeft') command = 'l'\r\n"
            "else if (e.key == 'ArrowRight') command = 'r'\r\n"
            "if (command) {\r\n"
            "    $.post('command', command);\r\n"
            "}\r\n"
            "})\r\n"
            "</script>\r\n"
            "</head>\r\n"
            "<body>\r\n"
            "<h1>Game State:</h1>\r\n"
            "<div id=\"game_state\">Player 1: (%d, %d), Player 2: (%d, %d)</div>\r\n"
            "</body>\r\n"
            "</html>\r\n",
            game_state.player1_x, game_state.player1_y,
            game_state.player2_x, game_state.player2_y);

    send(new_socket, http_response, strlen(http_response), 0);
  }
}

void* update_game_state_thread(void* arg) {
  while (1) {
    //update_game_state();
    sleep(1);
  }
  return NULL;
}

void setup_socket(int *server_fd, struct sockaddr_in *address) {
    int opt = 1;
    int addrlen = sizeof(*address);

    // Creating socket file descriptor
    if ((*server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(*server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(PORT);

    // Forcefully attaching socket to the port
    if (bind(*server_fd, (struct sockaddr *)address, sizeof(*address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(*server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

void game_loop(int server_fd, struct sockaddr_in address) {
    int addrlen = sizeof(address);
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, update_game_state_thread, NULL);

    while (1) {
        int new_socket;
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            continue;
        }

        handle_request(new_socket);
        close(new_socket);
    }
}

int main() {
    int server_fd;
    struct sockaddr_in address;

    setup_socket(&server_fd, &address);
    game_loop(server_fd, address);

    return 0;
}
