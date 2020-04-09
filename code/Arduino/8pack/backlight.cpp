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
    File: backlight.cpp
    Author: Charles Garcia
    Date: June 11, 2019
    Description: Implements backlighting setup and functions to the 8pack keypad
*/

/* Global libraries */
#include <Arduino.h>

// Project-specific libraries
#include "button.h"
#include "backlight.h"

/* Pin definitions stored as array */
const uint8_t ledArray[NUMKEYS] = {LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8};

/**
 * @brief   Setup the backlight pins on the 8pack
 * @param   None
 * @return  None
 */
void backlightSetup(){
  for(uint8_t i = 0; i < NUMKEYS; i++){
    pinMode(ledArray[i], OUTPUT);
  }
}

/**
 * @brief   Turn on all backlighting
 * @param   None
 * @return  None
 */
void backlightOn(){
  for(uint8_t i = 0; i < NUMKEYS; i++){
    digitalWrite(ledArray[i], HIGH);
  }
}

/**
 * @brief   Turn off all backlighting
 * @param   None
 * @return  None
 */
void backlightOff(){
  for(uint8_t i = 0; i < NUMKEYS; i++){
    digitalWrite(ledArray[i], LOW);
  }
}

/**
 * @brief   Blink all backlight LEDs once
 * @param   Effect delay in milliseconds, as unsigned 32-bit integer
 * @return  None
 */
void backlightBlinkOnce(uint32_t delay_ms){
    backlightOn();
    delay(delay_ms);
    backlightOff();
    delay(delay_ms);
}

/**
 * @brief   Start animation for 8pack backlight
 * @params  None
 * @return  None
 */
void backlightStartAnimation(uint32_t delay_ms){
    
    // Blink backlight twice
    backlightBlinkOnce(delay_ms*2);
    backlightBlinkOnce(delay_ms*2);

    // Turn on each backlight LED, one-by-one, slowly
    for(uint8_t i = 0; i < NUMKEYS; i++){
        digitalWrite(ledArray[i], HIGH);
        delay(delay_ms);
    }
}

/**
 * @brief   Turn on user-defined backlighting effects here. User implements their own effects here if desired
 * @params  User-defined
 * @return  None
 */
void backlightMainAnimation(){
  // Implement user backlighting effects here
}
