# Build notes

## PCB
The whole process was relatively straightforward. I uploaded the [production files](https://github.com/hazels-garage/bad-wings/tree/master/v1/production) to JLCPCB, who then created 5 PCBs with all the surface mounted components installed, that cost me US$44.73 including shipping.

## Other Components
* [Seed Studio XIAO BLE module](https://au.mouser.com/en/ProductDetail/Seeed-Studio/102010631?qs=sqEgtWRSLJ0onACN0vD2nA%3D%3D&countryCode=AU&currencyCode=AUD) This is the brains of the operation, ai got one with pre-soldered pins
* [35/mm Cirque Touch Pad](https://au.mouser.com/en/ProductDetail/Cirque/TM035035-2024-000?qs=wd5RIQLrsJhinTnUD8SbwA%3D%3D&countryCode=AU&currencyCode=AUD)
* 36 Kailh Choc V1 switches, I chose brown
* 36 Kailh Choc V1 hot swap sockets. These are optional, but they are cheap and make assembly so much easier than soldering the switches directly to the board 
* Choc V1 key caps, I was going to chose blank ones, but I found a store which had a full set on special
* LIPO battery. I used a 602626 400mAh, a smaller one might have made things easier
* A selection M2 screws, bolts and standoffs
* some L shaped header pins
* Rubber feet to stop the thing from sliding around
* Solder
* Electrical tape

## Tools
* Soldering Iron, I've got a Pinecil V2. USB C powered and just works.
* switch puller tool, optional but recommended
* key cap puller, same
* screw driver set for the screws and bolts
* UCB C Cable

## Case
The original guide has [STLs for the
cases](https://github.com/hazels-garage/bad-wings/tree/master/v1/cases/original)
I initially went with the
[top-ble.stl](https://github.com/hazels-garage/bad-wings/blob/master/v1/cases/original/top-ble.stl)
but because I hadn't used sockets for the XIAO the USB C hole didn't line up,
also I found it too tall.

I took the original top and hollowed it out a bit to fit the battery. [My
version](./top.stl) is a little cramped, and doesn't include a hole for the
power switch, but I'm happy with the low profile end result.

I used JLC3DP to print the case files white resin (cheaper) for the bottom, and
black for the top. I also had to thicken the bottom a little to make JLC happy
(I don't have ready access to a 3D Printer. sometimes I look at a thing and
realize it's going to open a whole new hyper fixation and time sink, then I back
away slowly)

(also see my [OpenSCAD](https://github.com/baralong/OpenSCAD) repo for some of
my current adventures in modeling)

## Build Guide
Taken from the original [build
guide](https://github.com/hazels-garage/bad-wings/blob/master/v1/README.md#build-guide),
use the original if you want to use socket headers to mount the XIAO. This isn't
exactly what I did, but it's what I'd do if I did it again.
* Install Switch Hot Swap Sockets
* Install Pin on the XIAO. This is to enable the battery charging circuit, you
  have to get it right so it goes through the hole in the PCB. This was a little
  fiddly but using an L shaped pin simplified things
* Solder XIAO directly to the PCB
* Insert switches (don't do the keycaps just yet)
* Connect ribbon cable to Cirque touchpad
* Connect Cirque to PCB
* Plug it in to your computer
* Flash [Firmware](../../../../artifacts/bad_wings%20raw_hid_adapter-xiao_ble__zmk-zmk.uf2)
* Test Cirque and switches
* Disconnect Cirque cable from Cirque
* Remove switches
* Solder on a battery, or solder on a socket for the battery. I went directly to
  the board because I used my modified lower profile case top and a larger
  battery. Be very careful with the polarity (black is negative, red positive)
* Insert PCB into top case, feed ribbon cable through hole
* Attach the ribbon cable to the cirque
* Insert the switches (don't do the keycaps just yet), these will hold the top
  to the board 
* Plug it in and test again
* I used 50mm black electrical tape to secure the Cirque
* I Used 10mm screws through the top, PCB, and base to hold it all together. For
  a cleaner result you could use short standoffs between the board and top, and
  then screws from the bottom   
*  Done.

## Things I'd do differently
* I'd probably use standoffs between the PCB and top, that would allow for
  thinner rubber feet
* Include a cutout for the power switch (if you do this, please send me a pull
  request, or just the file)
* The power switch is tiny, you meed a pencil or something to turn it off and
  on. Some slider or something to make that easier to get to would be nice