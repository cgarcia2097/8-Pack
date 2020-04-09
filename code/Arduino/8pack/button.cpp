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
    File: button.cpp
    Author: Charles Garcia
    Date: June 11, 2019
    Description:
      - Provides setup and button scanning to 8pack keyboard
      - Store button states in a variable for further processing
*/

/* Global libraries */
#include <Arduino.h>
#include <Bounce2.h>

// Project-specific header files
#include "button.h"

// Store all eight button states in a byte
volatile uint8_t buttonStates = 0;

// Bounce object declaration
Bounce button[NUMKEYS];

// Store pin assignments in an array
const byte pinArray[NUMKEYS] = {PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7, PIN_8};

/**
   @brief   Provide debouncing to Arduino GPIO pins
   @param   None
   @returns None
*/
void buttonSetup() {

  // Set up debouncing for buttons
  for (uint8_t i = 0; i < NUMKEYS ; i++) {
    button[i] = Bounce();
    button[i].attach(pinArray[i], INPUT_PULLUP);
    button[i].interval(8);
  }
}

/**
   @brief   Scan GPIO pins for rising/falling edges, and store states in a status variable
   @param   None
   @returns None
*/
void buttonScan() {
  for (uint8_t i = 0; i < NUMKEYS; i++) {
    button[i].update();

    // When button is pressed, set the corresponding bit
    if (button[i].fell()) {
      bitSet(buttonStates, i);
    }

    // When button is released, clear the corresponding bit
    if (button[i].rose()) {
      bitClear(buttonStates, i);
    }
  }
}
