/*
 
Copyright 2019 Charles Garcia

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
