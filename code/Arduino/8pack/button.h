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
    File: button.h
    Author: Charles Garcia
    Date: June 11, 2019
    Description: Header file for button.cpp, used for calling button.cpp functions
*/

#ifndef BUTTON_H
#define BUTTON_H

/* Global libraries */
#include <Arduino.h>

/* Number of keys */
#define NUMKEYS 8

/* PCB-specific settings */
//#define VER_1_1
//#define VER_1_2
#define VER_1_3
//#define VER_1_4

/* Pin definitions for 8pack Rev. 1.1 */
#ifdef VER_1_1
#endif

/* Pin definitions for 8pack Rev. 1.2 */

#ifdef VER_1_2
#endif

/* Pin definitions for 8pack Rev. 1.3 */
#ifdef VER_1_3
  #define PIN_1 18  
  #define PIN_2 19
  #define PIN_3 20
  #define PIN_4 21
  #define PIN_5 10
  #define PIN_6 16
  #define PIN_7 14
  #define PIN_8 15
#endif

/* Pin definitions for 8pack Rev. 1.4 */
#ifdef VER_1_4
  #define PIN_1 21
  #define PIN_2 20
  #define PIN_3 19
  #define PIN_4 18
  #define PIN_5 15
  #define PIN_6 14
  #define PIN_7 16
  #define PIN_8 10
#endif

/* button.cpp variables */
extern volatile uint8_t buttonStates;

/**
   @brief   Provide debouncing to Arduino GPIO pins
   @param   None
   @returns None
*/
extern void buttonSetup();

/**
   @brief   Scan GPIO pins for rising/falling edges, and store states in a status variable
   @param   None
   @returns None
*/
extern void buttonScan();

#endif
