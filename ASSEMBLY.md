# Assembly Guide (WIP Skeleton)
This doc should go over the basics of how to assemble the 8pack keypad. Order of assembly is important as backtracking  requires knowledge of desoldering. Currently a WIP

## Prerequisites
* Programming experience (if using Arduino)
* Knowledge of command-line tools (if using TMK/QMK)
* Basic soldering knowledge and experience (through-hole components)

## Plate Assembly (Optional, but must be decided early; assembled first)
For those that plan to add RGB underglow lighting to their keypad using the RGB plate, please follow these steps.

### Step 1 - Attach and solder LED strip to plate

### Step 2 - Attach and solder JST header to plate

## Board assembly
This applies to both the included RGB plate and other 3rd-party cases.

### Step 1 - Attach switches to the plate

### Step 2 - Attach and solder resistors to board

### Step 3 - Attach and solder reset button to board

### Step 4 - Attach and solder male headers to board

#### IMPORTANT NOTE: Take note of the switch style being used. Check if your switch is a Cherry-style or is a BOX-style switch. Seperate instructions for each style of switch are included.

### If working with BOX-style switches:

#### Step 5a - Attach and solder LEDs to board

#### Step 5b - Attach and solder keypad switches to board

### If working with Cherry-style switches

#### Step 5a - Attach and solder keypad switches to board

#### Step 5b - Attach and solder LEDs to board

### Step 6 - Attach and solder Pro Micro to board

### Step 8 - Attach JST Pins to Plate

### Step 8 - Connect the plate to the board using JST cable

### Step 9 - Attach bottom plate

## Flashing the default firmware (WIP)
If you are familiar with the firmware flashing cycle, this should be a refresher.

### Using Arduino 
* Install Arduino IDE and Sparkfun board drivers
* Using `Tools`->`Boards`, select `Sparkfun Pro Micro`
* Using `Tools`->`Port`, select the port in which the Pro Micro appears
* Open provided Arduino code in Arduino IDE and compile
* Hit the `Upload` button to flash the firmware into the board

### Using TMK/QMK


## Mods going forward (WIP)

### Using Arduino

### Using TMK/QMK









