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
either expressed or implied, of the DIY-8-Button-Keypad project.

*/

#include <Keyboard.h>
#include <Bounce2.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 0
#define NUMKEYS 8

// Edit the buttons you want pressed here
#define KEY_1 'v'
#define KEY_2 'c'
#define KEY_3 'x'
#define KEY_4 'z'
#define KEY_5 'a'
#define KEY_6 's'
#define KEY_7 'd'
#define KEY_8 'f'

// Pins used by the buttons
#define PIN_1 21
#define PIN_2 20
#define PIN_3 19
#define PIN_4 18
#define PIN_5 15
#define PIN_6 16
#define PIN_7 14
#define PIN_8 10

// Pins used by the buttons
#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5
#define LED_5 6
#define LED_6 7
#define LED_7 8
#define LED_8 9

// Neopixel declaration
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

// Some default colors
// Primary colours
#define RED     strip.Color(255,0,0)
#define BLUE    strip.Color(0,0,255)
#define GREEN   strip.Color(0,255,0)

// Secondary colours
#define PURPLE  strip.Color(255,0,255)
#define YELLOW  strip.Color(255,255,0)
#define CYAN    strip.Color(0,255,255)
#define WHITE   strip.Color(255,255,255)

// User-made
#define ORANGE  strip.Color(255,63,0)

// Arrays used for the for-loop sections of the program
const byte pinArray[NUMKEYS] = {
  PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7, PIN_8
};

const byte keyArray[NUMKEYS] = {
  KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8
};

const byte ledArray[NUMKEYS] = {
  LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8
};

const uint32_t colorArray[NUMKEYS] = {
  RED, BLUE, GREEN, PURPLE, YELLOW, CYAN, WHITE, ORANGE
};

// Debouncing declaration
Bounce button[NUMKEYS];

// State variables for colour change
bool prevColour = false, currColour = false;

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

void startAnimation(uint32_t wait){
  for(uint8_t i = 0; i < NUMKEYS; i++){
    for(uint8_t j=0; j< strip.numPixels(); j++) {
      strip.setPixelColor(j, colorArray[i]);
    }
    strip.show();
    delay(wait);
  }
}

void setup() {

  for(uint8_t i = 0; i < NUMKEYS ; i++){
    
    // Set up the buttons 
    button[i] = Bounce();
    button[i].attach(pinArray[i], INPUT_PULLUP);
    button[i].interval(5);

    // Set up the LEDs
    pinMode(ledArray[i], OUTPUT);
  }

  // LED strip setup
  strip.begin();
  strip.setBrightness(255);
  strip.show(); // Initialize all pixels to 'off'

  // Start animation when plugging in
  startAnimation(250);

  // Static underglow for the time being
  for(uint8_t j=0; j< strip.numPixels(); j++) {
    strip.setPixelColor(j, ORANGE);
  }
  strip.show();

  // Initialize keyboard functions
  Keyboard.begin();
}

void loop() {
  uint32_t i, j;

  // Scan the buttons and press macros if needed
  for(i=0; i < NUMKEYS; i++) {
    button[i].update();
 
    if(button[i].fell()){
      Keyboard.press(keyArray[i]);
      digitalWrite(ledArray[i], HIGH);
    }
      
    if(button[i].rose()){
      Keyboard.release(keyArray[i]);
      digitalWrite(ledArray[i], LOW);       
    }
  }  
}

/**
 * 
 * 
 */
