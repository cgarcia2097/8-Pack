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
  * File: main.cpp
  * Author: Charles Garcia
  * Date: June 11, 2019
  * Description: Main .cpp for the 8pack project
  *
*/

// Global libraries
#include <Arduino.h>

// Project-specific Libraries
#include "button.h"
#include "backlight.h"
#include "underglow.h"
#include "keys.h"

// Timing variable
uint32_t curTime = 0, prevTime = 0;

/**
 * @brief   8pack setup functions
 * @params  None
 * @returns None
 */
 void setup(){
  // Initialize serial 
  Serial.begin(115200);

  // Initialize buttons
  buttonSetup();

  // Initialize underglow
  underglowSetup();
  underglowStartAnimation(125);

  // Initialize backlighting
  backlightSetup();
  backlightStartAnimation(75);
}

/**
 * @brief   8pack main function
 * @params  None
 * @returns None
 */
 void loop(){
   uint8_t prevState = buttonStates;
   curTime = millis();

  // Scan buttons
  buttonScan();
  
  // Send keypresses upon change in buttonState
  if(prevState != buttonStates){
      sendKeyPress(buttonStates);
  }

  // Lighting section
  underglowMainAnimation(buttonStates);
 }