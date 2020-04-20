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
    File: underglow.h
    Author: Charles Garcia
    Date: June 11, 2019
    Description: Header file containing pin definitions and functions for underglow.cpp
*/

#ifndef UNDERGLOW_H
#define UNDERGLOW_H

// Global libraries
#include <Arduino.h>

// Neopixel Pin
#define NEOPIXEL_PIN 0

// Neopixel strip length
#define NEOPIXEL_LENGTH 8

// Neopixel effect delay in milliseconds
#define NEOPIXEL_EFFECT_DELAY_MS 50

// Pre-defined user colours
#define RED     strip.Color(255,0,0)
#define BLUE    strip.Color(0,0,255)
#define GREEN   strip.Color(0,255,0)
#define PURPLE  strip.Color(255,0,255)
#define YELLOW  strip.Color(255,255,0)
#define CYAN    strip.Color(0,255,255)
#define WHITE   strip.Color(255,255,255)
#define ORANGE  strip.Color(255,63,0)

// Effects 
//#define RAINBOW_MODE
#define RAINBOW_CYCLE_MODE
#define INTERACTIVE_LIGHTING

/*
 * @brief   Calculate rainbow colour based on strip position
 * @param   Strip position as unsigned byte
 * @returns 32-bit strip color
 */
extern uint32_t Wheel(byte WheelPos);

/**
 * @brief   Set one color for the whole strip
 * @param   Unsigned 32-bit number, representing RGB value
 * @returns None
 */
extern void underglowSetup();

/**
 * @brief   Set one color for the whole strip
 * @param   Unsigned 32-bit number, representing RGB value
 * @returns None
 */
extern void underglowSetColor(uint32_t color);

/**
 * @brief   Play startup animation of keypad
 * @param   Unsigned 32-bit number, lower number == faster animation speed
 * @returns None
 */
extern void underglowStartAnimation(uint32_t delay_ms);

/**
 * @brief   Animation played during regular kaypad operation. User implements their own effects here if desired
 * @param   User-defined
 * @returns None
 */
extern void underglowMainAnimation(uint8_t keyPressed);

#endif