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
    File: keys.cpp
    Author: Charles Garcia
    Date: June 11, 2019
    Description: Reads the stored button states and send keypresses
*/

// Global libraries
#include <Arduino.h>
#include <Keyboard.h>

// Project-specific header files
#include "keys.h"
#include "keybinds.h"

/**
 * @brief   Iterate and send keypresses of the selected array of macros until STOP_CODE entry is encountered
 * @params  Unsigned byte from 0-7, indicating the button pressed
 * @returns 0 on success
 */
void pressMacroArray(uint8_t keyPressed){
  uint8_t i = 0;

  // Iterate through macroArray until entry is STOP_CODE, and send keypresses to PC
  while((i < HID_USB_LIMIT)){
    if(macroArray[keyPressed][i] == 0xff){
      break;
    }
    Keyboard.press(macroArray[keyPressed][i]);
    i++;
  }
}

/**
 * @brief   Iterate and release keypresses of the selected array of macros until STOP_CODE entry is encountered
 * @params  Unsigned byte from 0-7, indicating the button pressed
 * @returns None
 */
void releaseMacroArray(uint8_t keyPressed){
  uint8_t i = 0;

  // Iterate through macroArray until entry is STOP_CODE, and send keypresses to PC
  while((i < HID_USB_LIMIT)){
    if(macroArray[keyPressed][i] == 0xff){
      break;
    }
    Keyboard.release(macroArray[keyPressed][i]);
    i++;
  }
}

/**
 * @brief   Read buttonStates and send keypresses based on the bit selected
 * @param   None
 * @returns None
 */
void sendKeyPress(uint8_t keyStates){
  uint8_t i = 0;

  #ifdef KEYPRESS_MODE
  // For each bit 
  for(i = 0; i < NUMKEYS; i++){

    // If bit(i) is '1'
    if(bitRead(keyStates, i)){
      pressMacroArray(i);
    }
    // If bit(i) is '0'
    else{
      releaseMacroArray(i);
    }
  }
  #endif

  // TODO: Implement key playback tutorial
  #ifdef PLAYBACK_MODE
  #endif
}
