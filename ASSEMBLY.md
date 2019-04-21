# Assembly Guide (WIP Skeleton)
This doc should go over the basics of how to assemble the 8pack keypad. Order of assembly is important as backtracking  requires knowledge of desoldering.

## Prerequisites
* Basic soldering knowledge and experience (through-hole components, orientation)
* Basic electronics knowledge 

## Plate Assembly (Optional, but must be decided early; assembled first)
For those that plan to add RGB underglow lighting to their keypad using the RGB plate, please follow these steps.

### Step 1 - Attach and solder LED strip to plate
Take notice of the arrows both on the LED strip and the plate. They both must point in the same direction when mounting them.

(Insert pic here)

After peeling off the back cover, stick the LED strip onto the board, aligning the LED strip's pad with the board's. Make sure the LED strip is aligned to the middle of the board.

(Insert pic here)

In this case my prototype board has oversized plate pads, slightly misaligning with the LED pads. 

(Insert pic here)

Nothing a solder bridge can't fix, but the pad sizing will be fixed in the next revision.

### Step 2 - Attach and solder JST header to plate
Solder the JST socket onto the plate.

(insert pic here)

## Board assembly
This applies to both the included RGB plate and other 3rd-party cases.

### Step 1 - Attach switches to the plate
With the 8pack logo facing downwards, attach the switches by pushing the keyswitch into the square cutouts. Make sure the keyswitch pins are facing the long edge of the board, and all keyswitches are in the same orientation.

(insert pic here)

### Step 2 - Attach and solder resistors to board
We want these resistors to fit flush with the board, so firstly, bend the resistor pins 90 degrees from the tips of the resistor like so: 

(Pic goes here)

You should end up with a U-shaped component. Next, insert these resistor leads into the holes marked by these labels:

(Insert pic here)

The resistors should be flat against the board. It is also helpful to bend the resistor leads at the through-hole to prevent them from falling out during soldering.

(Insert pic here)

Solder the resistors, and trim the ends afterward. For the uninitiated, you are looking at a cone-shaped mound of solder, not a bubble of solder nor a partially-filled hole.

(insert pic)

### Step 3 - Attach and solder reset button to board
Find the button label on the board, and insert the switch there.

(insert pic)

Flip the board, and solder the exposed button leads on the button. As a reminder, cone-shaped mound of solder.

(insert pic)

### Step 4 - Attach and solder male headers to board
It is relatively difficult to solder the headers at this step.

### Step 5 
#### IMPORTANT NOTE: Take note of the switch style being used. Check if your switch is a Cherry-style or is a BOX-style switch. Seperate instructions for each style of switch are included.

##### If working with BOX-style switches:

###### Step 5a - Attach and solder LEDs to board

###### Step 5b - Attach and solder keypad switches to board

##### If working with Cherry-style switches

###### Step 5a - Attach and solder keypad switches to board

###### Step 5b - Attach and solder LEDs to board

### Step 6 - Attach and solder Pro Micro to board

### Step 8 - Attach JST Pins to Plate

### Step 8 - Connect the plate to the board using JST cable

### Step 9 - Attach bottom plate
