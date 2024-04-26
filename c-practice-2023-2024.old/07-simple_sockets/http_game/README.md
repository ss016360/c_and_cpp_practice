## Change to VM settings to let you make this work there

In settings/Network, change the network type to "Bridged"

Then compile this in the VM, and run it.
You should then be able to access it from your host (PC)
using the IP address it reports when it starts, and the
port 8124

For instance, on my machine it currently reports:

enp0s3 IP Address 192.168.0.32

so I can use this URL in my browser on my PC:
http://192.168.0.32:8124

and then use my cursor keys to get the letter A to run away 
from the scary letter B that is chasing it.

Genuinely seconds of fun to be had!


**Note**

This is __not__ production quality code, I have left out a 
lot of the "boilerplate" code that would make it more 
robust.    In the real world, we'd almost always use an 
existing http library for something like this, but the
approach shown here has the benefit of revealing some of 
the underlying 'plumbing' that needs to be done.
