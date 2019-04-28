# Assembly Guide (WIP Skeleton)
This doc should go over the basics of how to assemble the 8pack keypad. If the pictures look out of order, these are taken from another keypad build I am working on. The steps remain the same, however. Same reason for the extra components on the board

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

#### Soldering Tools
* __Soldering Iron__ - The tool that melts solder and joins electrical somponents together
* __Desoldering pump and/or solder wick__ - Used to remove solder from a joint for fixing small mistakes 
* __Soldering flux__ - A paste that helps solder flow more easily; usually used in desoldering
* __Solder__ - The alloy used in joining electrical components; melts under a soldering iron.
* __Soldering sponge__ - Used to clean the tip of a soldering iron
* __Soldering fan (Fume Extractor)__ - Used to remove smoke from the soldering process. 

#### Parts in the kit:
* __Keyswitch/button__ - What the microcontroller checks to send keypresses
* __Keycap__ - What your fingers press to interact with your keypad
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

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0127.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0134.JPG)

### Step 2 - Attach and solder resistors to board
We want these resistors to fit flush with the board, so firstly, bend the resistor leads 90 degrees from the tips of the resistor. You should end up with a U-shaped resistor. 

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0143.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0144.JPG)

Next, insert the resistor leads into the through-holes marked by the `R` labels:

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0146.JPG)

The resistors should be flat against the board. It is also helpful to bend the resistor leads at the joint to prevent them from falling out during soldering.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0147.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0152.JPG)

Solder the resistors, and trim the ends afterward.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0154.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0161.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0165.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0167.JPG)

### Step 3 - Attach and solder reset button to board
The button label is right under the 8pack logo. Insert the switch there.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0173.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0175.JPG)

Flip the board, and solder the exposed button leads on the button. As a reminder, cone-shaped mound of solder.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0177.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0179.JPG)

### Step 4 - Attach and solder male headers to board
The short end of the header leads attach to the bottom side of the board.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0183.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0184.JPG)

It is relatively difficult to solder the headers at this step. One method is to fill one hole with solder, and push one the header leads through the hole while the solder is hot. Be careful that you are not holding the same header lead under the solder-filled hole, as that will cause burns.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0185.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0186.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0189.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0190.JPG)

Now solder the rest of the exposed header leads

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0194.JPG)


### Step 5 - Attach and solder keypad switches to board
At this step, please check whether all your keyswitches are in the same orientation. If not, refer to Step 1 after popping out the buttons. 

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0197.JPG)

With the keyswitches currently mounted onto the plate, align the keyswitch through-holes with the keyswitch leads and slide the board into the keyswitch leads. 

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0199.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0200.JPG)

At this point, you can see the keyswitch leads sticking out of the keyswitch holes. Solder these pins to the board.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0205.JPG)

### Step 6 - Attach and solder LEDs to board
This step can be done one-by-one per LED, or on all LEDs at once. There is a circular slot on the keyswitch where an LED can be inserted. Insert them through here.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0207.JPG)

Make sure on the other side of the board, that the longer LED lead is on the circular pad; the shorter LED lead is on the square pad.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0209.JPG)

Bend the leads in the joint area to prevent it from falling out. Do this for the other LEDs you have attached (if any).

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0211.JPG)

Solder the joint area, and trim the excess leads afterwards. Repeat for any other LEDs on the board.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0221.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0224.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0226.JPG)

## Step 7 - Attach the Pro Micro onto the board
With the USB port facing away from the board and in the same direction as the `USB` label, insert the Pro Micro into the headers. Trim the long side of the headers by inserting the Pro Micro onto the headers, and trimming just above it.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0228.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0230.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0234.JPG)

Add solder on top of the joints to connect the Pro Micro's pins to the rest of the keypad

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0236.JPG)
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0238.JPG)

### Step 8 - Program the Pro Micro

Head over to the  ![PROGRAMMING](PROGRAMMING.md) section.

### Step 9 - Attach bottom plate and keycaps
Perform this step after completing ![Step 8](PROGRAMMING.md). 

Attach the M3 standoffs to the bottom plate using the provided M3 screws.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0239.JPG)

Once done, align the top plate holes with the other end of the standoffs, and screw in the top plate.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0241.JPG)

Now attach keycaps.

![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Keypad/Photos/No%20RGB/IMG_0245.JPG)

Voila, you now have a functional keypad.

