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

/*
  CREDITS:
    - Adafruit Neopixel Library example "strandtest.ino", for providing the Wheel, Rainbow and Rainbow cycle calculations
*/

/**
    File: underglow.cpp
    Author: Charles Garcia
    Date: June 11, 2019
    Description: Provides setup and underglow animations for the 8pack keypad
*/

// Global libraries
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Project-specific libraries
#include "underglow.h"
#include "button.h"

// Neopixel declaration
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NEOPIXEL_LENGTH, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// Store underglow colors in array
const uint32_t colorArray[NUMKEYS] = {RED, BLUE, GREEN, PURPLE, YELLOW, CYAN, WHITE, ORANGE};

// Timing variables
extern uint32_t curTime, prevTime;

// Counters
uint8_t i = 0, j = 0;

/*
 * @brief   Calculate rainbow colour based on strip position
 * @param   Strip position as unsigned byte
 * @returns 32-bit strip color
 */
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

/**
 * @brief   Set one color for the whole strip
 * @param   Unsigned 32-bit number, representing RGB value
 * @returns None
 */
void underglowSetup(){
  strip.begin();
  strip.setBrightness(255);
  strip.show(); // Initialize all pixels to 'off'
}

/**
 * @brief   Set one color for the whole strip
 * @param   Unsigned 32-bit number, representing RGB value
 * @returns None
 */
void underglowSetColor(uint32_t color){
    for(uint8_t j=0; j< strip.numPixels(); j++) {
      strip.setPixelColor(j, color);
    }  
    strip.show();
}

/**
 * @brief   Play startup animation of keypad
 * @param   Unsigned 32-bit number, lower number == faster animation speed
 * @returns None
 */
void underglowStartAnimation(uint32_t delay_ms){

  // Flash the Underglow
  for(uint8_t i = 0; i < NUMKEYS; i++){
    underglowSetColor(colorArray[i]);
    strip.show();
    delay(delay_ms);
  }
}

/**
 * @brief   Animation played during regular keypad operation. User implements their own effects here if desired
 * @param   Switch state, as unsigned byte. Can be used for per-key effects
 * @returns None
 */
void underglowMainAnimation(uint8_t keyPressed){

  switch(keyPressed){

    // If keypad is not pressed, do background animation 
    // Uses a non-blocking delay
    case 0:
      if((curTime - prevTime) < NEOPIXEL_EFFECT_DELAY_MS){
        return;
      }
      
      prevTime = curTime;
    
      // Depending on underglow.h definitions, the compiled underglow effect will differ
      // TODO: Store settings in EEPROM instead of #define macros
      for(i = 0; i < strip.numPixels(); i++) {
        #ifdef RAINBOW_CYCLE_MODE
          strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
        #endif
    
        #ifdef RAINBOW_MODE
          strip.setPixelColor(i, Wheel((i+j) & 255));
        #endif
      }
      
      strip.show();
      j++;      
    break;

    // If pressed, set appropriate color
    #ifdef INTERACTIVE_LIGHTING
    case 1:
      underglowSetColor(colorArray[0]);
      break;

    case 2:
      underglowSetColor(colorArray[1]);
      break;

    case 4:
      underglowSetColor(colorArray[2]);
      break;

    case 8:
      underglowSetColor(colorArray[3]);
      break;

    case 16:
      underglowSetColor(colorArray[4]);
      break;

    case 32:
      underglowSetColor(colorArray[5]);
      break;

    case 64:
      underglowSetColor(colorArray[6]);
      break;

    case 128:
      underglowSetColor(colorArray[7]);
      break;
    #endif

    // Unsupported states
    default:
      break;

  }
}