# Programming Guide for 8pack
This guide will go through the method of flashing default firmware into the 8pack using the Arduino environment. Other methods are under consideration at the moment. 

### 1 - Download the required software
- Install the Arduino IDE from the Arduino website. [Link](https://www.arduino.cc/en/Main/Software)

![img]()

### 2 - Setting up the flashing environment
The 8pack requires a specific environment at the moment to reprogram it, as no app exists at the moment.

#### 2.1 - Installing the Libraries
Once installed, download the required libraries by clicking `Sketch`->`Include Library`->`Manage Libraries` and install these libraries:
  - Adafruit Neopixel
  - Bounce2

![img]()

Alternatively one can manually add the ZIP files from their respective Github pages by clicking `Sketch`->`Include Library`->`Add .ZIP Library`
  - Adafruit Neopixel: https://github.com/adafruit/Adafruit_NeoPixel/archive/master.zip
  - Bounce2: https://github.com/thomasfredericks/Bounce2/archive/master.zip

![img]()

#### 2.2 - Programming for the Pro Micro
To set the environment to program for a Pro Micro, click `Tools`->`Board`->`Arduino Leonardo`. 

![img]()

While the Pro Micro has its own [installation guide](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/all), it seems to share the same pin labels as the Arduino Leonardo. Choosing the Leonardo allows us to skip the hassle of setting up the Pro Micro manually, but may be subject to change later down the line as Sparkfun may change their design.

### 3 - Get the code from the repository
Download and unpack the project: https://github.com/cgarcia2097/8-Pack/archive/master.zip. Navigate to the folder `code/Arduino/8pack `. Then open the file `8pack.ino` in Arduino by clicking `File`->`Open`.

### Editing the keybinds
Click over to the tabs and select `keybinds.h`

(WIP)

### Compiling and uploading the code
- Plug the keypad into your PC.
- Click `Tools`->`Ports` and select the port with (Arduino/Genuino) beside the port name
- Click `Verify` and `Upload`.

### Testing out the keypad bindings
Give the keys some quick presses (WIP)

### Editing on PlatformIO
WIP

### TMK/QMK support
A third-party has created a QMK port of my keypad, which can be found here: https://github.com/qmk/qmk_firmware/tree/master/keyboards/8pack


