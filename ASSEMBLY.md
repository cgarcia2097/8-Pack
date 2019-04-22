# Assembly Guide (WIP Skeleton)
This doc should go over the basics of how to assemble the 8pack keypad. There are other compoenents currently on the board like LED strips; please ignore them for the time being as this is a simplified version of the 8pack keypad. 

#### Prerequisites
* Basic soldering knowledge and experience (through-hole components, orientation)
* Basic electronics knowledge 

#### Terms used frequently in this guide
* __PCB/Board__ - A printed circuit board. It contains copper tracks in which multiple electronic components are connected together after soldering.
* __Through-hole__ - part of an exposed copper track where electronic components are attached and soldered.
* __Leads__ - long metal wires attached to electronic components. Usually found on simple components like resistors, keyswitches and LEDs
* __Headers__ - A type of connector used to connect components together. Male headers have exposed leads, and female headers have sockets
* __Pins__ - Connections to a microcontroller's ports, usually attached to other electronic components in order to interact with them.
* __Joint__ - the place where a component's lead intersects with a through-hole.

#### Tools required
* Soldering Iron
* Soldering Wick
* Soldering Flux
* Solder
* Soldering Sponge
* Soldering fan (Fume Extractor
* Phillips head screwdriver

#### Parts in the kit:
* __Keyswitch/button__ - What your fingers press to interact with your keypad
* __Plate__ - Where the keyswitches are mounted; also protects the electronic components from direct contact.
* __Resistor__ - Electronic component used to protect the LED from burning out
* __LED__ - The lighting on the keypad 
* __Header__ - A connector used for attaching the Pro Micro
* __PCB__ - The board responsible for holding the keypad together
* __Microcontroller__ - The module responsible for reading the switches and flashing the LEDs. 
* __Standoffs__ - A really long nut with threads on the inside, used to fix/mount boards in place. Usually used with the appropriately-sized screw.

## Board assembly
This section delves into the assembly of the 8pack keypad. Order of assembly is important, as backtracking the steps requires knowledge of desoldering (a difficult process even for experienced hobbyists). There are also sub-steps in the main steps outlined above, which also need to be followed in that order.

To avoid confusion, the __board__ refers to the keypad PCB, as the Pro Micro is a microcontroller _board_.

### Step 1 - Attach switches to the 8pack top plate
With the 8pack logo facing downwards, attach the switches by pushing the keyswitch into the square cutouts. Make sure the keyswitch leads are facing the long edge of the board, and all keyswitches are in the same orientation.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2237.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2238.JPG)

### Step 2 - Attach and solder resistors to board
We want these resistors to fit flush with the board, so firstly, bend the resistor leads 90 degrees from the tips of the resistor like so: 

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2240.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2241.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2242.JPG)

You should end up with a U-shaped resistor. Next, insert the resistor leads into the through-holes marked by these labels:

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2243.JPG)

The resistors should be flat against the board. It is also helpful to bend the resistor leads at the joint to prevent them from falling out during soldering.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2244.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2247.JPG)

Solder the resistors, and trim the ends afterward. For the uninitiated, you are looking at a cone-shaped mound of solder, not a bubble of solder nor a partially-filled hole.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2250.JPG)

Trimmed:
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2255.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2256.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2257.JPG)

### Step 3 - Attach and solder male headers to board
The short end of the header leads attach to the bottom side of the board.

Top Side:
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2259.JPG)

Bottom Side:
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2270.JPG)

It is relatively difficult to solder the headers at this step. One method is to fill one hole with solder, and push one the header leads through the hole while the solder is hot. Be careful that you are not holding the same header lead under the solder-filled hole, as that will cause burns.

In this case I also used a breadboard to keep the header leads steady.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2262.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2263.JPG)

Now solder the rest of the exposed header leads

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2265.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2268.JPG)

### Step 4 - Attach and solder reset button to board
The button label is right under the 8pack logo. Insert the switch there.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2270.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2271.JPG)

Flip the board, and solder the exposed button leads on the button. As a reminder, cone-shaped mound of solder.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2274.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2275.JPG)

## Step 5 - Trim the headers

Trim the long side of the headers. This is easily done by inserting the Pro Micro onto the headers, and trimming just above the Pro Micro's board.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2277.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2280.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2281.JPG)

Remove the Pro Micro afterwards. There are still other steps to do afterward.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2283.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2286.JPG)

### Step 6 - Attach and solder keypad switches to board
At this step, please check whether all your keyswitches are in the same orientation. 

![]()

With the keyswitches currently mounted onto the plate, align the keyswitch through-holes with the keyswitch leads and slide the board into the keyswitch leads. 

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2236.JPG)

At this point, you can see the keyswitch leads sticking out of the keyswitch holes. Solder these pins to the board.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2305.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2306.JPG)

### Step 7 - Attach and solder LEDs to board
This step can be done one-by-one per LED, or on all LEDs at once. 

There is a circular slot on the keyswitch where an LED can be inserted. Insert them through here.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2308.JPG)

Make sure on the other side of the board, that the longer LED lead is on the circular pad; the shorter LED lead is on the square pad.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2309.JPG)

Bend the leads in the joint area to prevent it from falling out. Do this for the other LEDs you have attached (if any).

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2311.JPG)

Solder the joint area, and trim the excess leads afterwards. Repeat for any other LEDs on the board.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2313.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2314.JPG)

### Step 8 - Attach and solder Pro Micro to board
With the USB port facing away from the board and in the same direction as the `USB` label, insert the Pro Micro into the headers you trimmed earlier. Make sure it is as flush as possible.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2318.JPG)

Once finished, add solder on top of the joints to connect the Pro Micro's pins to the rest of the keypad

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2321.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/IMG_2323.JPG)


Head over to the  ![PROGRAMMING](PROGRAMMING.md) section after completing this step.

### Step 9 - Attach bottom plate
Perform this step after completing the ![PROGRAMMING](PROGRAMMING.md) section. 

Attach the M3 standoffs to the top plate using the provided M3 screws.

![]()

Once done, align the bottom plate holes with the other end of the standoffs. Attach the bottom plate once aligned.

![]()

Voila, you now have a functional keypad.

![]()
