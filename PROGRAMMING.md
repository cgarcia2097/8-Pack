# Programming guide for 8pack
This guide will go through the method of flashing default firmware into the 8pack using the Arduino environment. Other methods are under consideration at the moment. 

## Using Arduino
### Download and install the Arduino IDE
Download the Arduino IDE ![here](https://www.arduino.cc/en/Main/Software) and install it to your machine.

### Download the Sparkfun Board Drivers
In the Arduino IDE, open `File`-> `Preferences`. In the `Additional Boards Manager URLs` box, paste this link inside: ```https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json```

Once that's done, open `Tools`->`Board`->`Boards Manager`. In the search box, type `sparkfun` and click `Install` on the 'Sparkfun AVR Boards' package. 

Sparkfun also has a guide for that ![here](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/all)

### Set up the programming environment
In the Arduino IDE, open `Tools`-> `Boards`. Select `Sparkfun Pro Micro` from the selection of boards.

Once that is done, open `Tools`-> `Port`. Select the port that appears here.

### Download and install the `Bounce2` debouncing library
Download the library ![here](https://github.com/thomasfredericks/Bounce2/archive/master.zip). 

Once downloaded, open the Arduino IDE. Open `Sketch`->`Include Library`->`Manage Libraries`. Select the `Bounce2.zip` file you just downloaded.

### Copy code from the repository
Go ![here](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.2/Arduino%20Code/8-Pack.ino) to open the keypad code. Copy the code and paste it in the Arduino text editor.

### Compile the code
On the top-left corner, hit the `Compile` button to compile the keypad code. If `Done compiling` appears, then you have successfully created keypad firmware.

### Flash the board with your compiled code
Beside the `Compile` button, click on the `Upload` button to upload the compiled keypad code to the keypad. If `Done Uploading` appears, then you have successfully uploaded the code to the board.

### Test if the code works
Open up a text editor or an office app, and press the keys. If letters are appearing on the screen, then you have a working keypad.

## Further readings
This section is for those who wish to extract more functionality out of the keypad.

### Board Layout 
![img](https://github.com/cgarcia2097/8-Pack/blob/8-pack-updates/Ver.%201.1/keypad/schematic.pdf)

The board layout is a simple layout. Pins A3 to 10 on the Pro Micro (Arduino pin numbers) correspond to SW1 to SW8 on the keypad, while pins 2 to 9 correspond to the LEDs on SW1 to SW8 respectively. The keyswitches are wired directly to `GND`, requiring the use of `INPUT_PULLUP` when setting up the pins in Arduino.

The buttons can be accessed through Arduino's `digitalRead()` or using Bounce2's `button.fell()`/`button.rose()` (detecting falling and rising edges). The LEDs can be accessed and programmed though `digitalWrite()`.

### Multiple Macros
TODO

### TMK/QMK support
TODO
