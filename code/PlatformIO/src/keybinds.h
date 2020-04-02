/*
  Copyright (c) 2019, Charles Garcia
  All rights reserved.
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  The views and conclusions contained in the software and documentation are those
  of the authors and should not be interpreted as representing official policies,
  either expressed or implied, of the 8pack project.
*/

/**
    File: keybinds.h
    Author: Charles Garcia
    Date: June 11, 2019
    Description: Contains 8pack keybinds
*/

#ifndef KEYBINDS_H
#define KEYBINDS_H

/* Global libraries */
#include <Arduino.h>
#include <Keyboard.h>

/* Project-specific libraries */
#include "keys.h"
#include "button.h"

// Array of macros. Change your keybiands here.
// Each button has up to six keypresses available, assuming one button is pressed at a time
// HID_USB has a limit of six keypresses sent over USB
// More info on modifiers here: https://www.arduino.cc/en/Reference/KeyboardModifiers
// TODO: Guide on how to change keypresses

const unsigned char macroArray[NUMKEYS][HID_USB_LIMIT] = {
  {KEY_ESC, STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE},
  {'d', STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE},
  {'s', STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE},
  {'a', STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE},
  {'`', STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE},
  {'c', STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE},
  {'x', STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE},
  {'z', STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE, STOP_CODE},
};

#endif