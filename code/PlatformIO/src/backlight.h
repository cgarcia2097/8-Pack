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
    File: backlight.h
    Author: Charles Garcia
    Date: June 11, 2019
    Description: Header files containing pin definitions and functions for the 8pack backlighting
*/

#ifndef BACKLIGHT_H
#define BACKLIGHT_H

/* Global libraries */
#include <Arduino.h>

/* Arduino-style pin definitions for backlight LEDs */
#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5
#define LED_5 6
#define LED_6 7
#define LED_7 8
#define LED_8 9

/**
 * @brief   Setup the backlight pins on the 8pack
 * @param   None
 * @return  None
 */
extern void backlightSetup();

/**
 * @brief   Turn on the 8pack backlighting
 * @param   None
 * @return  None
 */
extern void backlightOn();

/**
 * @brief   Turn off the 8pack backlighting
 * @param   None
 * @return  None
 */
extern void backlightOff();

/**
 * @brief   Blink all backlight LEDs once
 * @param   Effect delay in milliseconds, as unsigned 32-bit integer
 * @return  None
 */
extern void backlightBlinkOnce(uint32_t delay_ms);

/**
 * @brief   Start animation for 8pack backlight
 * @params  None
 * @return  None
 */
extern void backlightStartAnimation(uint32_t delay_ms);

/**
 * @brief   Turn on user-defined backlighting effects here. User implements their own effects here if desired
 * @params  None
 * @return  None
 */
extern void backlightMainAnimation();

#endif