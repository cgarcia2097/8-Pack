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

// Change if adding more or less buttons
#define NUMKEYS 8

// Edit the buttons you want pressed here
#define KEY_1 'z'
#define KEY_2 'x'
#define KEY_3 'c'
#define KEY_4 'v'
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
#define PIN_6 14
#define PIN_7 16
#define PIN_8 10

// Pins used by the LEDs
#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5
#define LED_5 6
#define LED_6 7
#define LED_7 8
#define LED_8 9

// Arrays used for the for-loop sections of this program
const byte pinArray[NUMKEYS] = {
  PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7, PIN_8 
};

const byte keyArray[NUMKEYS] = {
  KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8
};

const byte ledArray[NUMKEYS] = {
  LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8
};

Bounce button[NUMKEYS];

void setup() {

  for(uint8_t i = 0; i < NUMKEYS ; i++){

    // Initialize buttons w/ debounce code
    button[i] = Bounce();
    button[i].attach(pinArray[i], INPUT_PULLUP);
    button[i].interval(5);

    // Initialize LEDs
    pinMode(ledArray[i], OUTPUT);
  }
}

void loop() {

  // Scan each button individually
  for(uint8_t i = 0; i < NUMKEYS; i++){
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
