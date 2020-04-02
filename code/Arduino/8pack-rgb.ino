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
#define EFFECT_DELAY_MS 50

/* Macro Settings */
#define SIMPLE_MODE
//#define MULTIKEY_MODE

/* PCB-specific settings */
//#define VER_1_1
#define VER_1_PLUS
//#define VER_1_4

/* Effects */
#define RAINBOW_MODE
#define INTERACTIVE_LIGHTING
//#define RAINBOW_CYCLE_MODE

// Edit the Keybinds you want pressed here
#define KEY_1 'z'
#define KEY_2 'x'
#define KEY_3 'c'
#define KEY_4 '`'
#define KEY_5 'a'
#define KEY_6 's'
#define KEY_7 'd'
#define KEY_8 KEY_ESC
  
#ifdef VER_1_1
// Pins used by the buttons
#define PIN_1 15
#define PIN_2 14
#define PIN_3 16
#define PIN_4 10
#define PIN_5 21
#define PIN_6 20
#define PIN_7 19
#define PIN_8 18
#endif

#ifdef VER_1_PLUS
// Pins used by the buttons
#define PIN_1 21
#define PIN_2 20
#define PIN_3 19
#define PIN_4 18
#define PIN_5 15
#define PIN_6 14
#define PIN_7 16
#define PIN_8 10
#endif

#ifdef VER_1_4
// Pins used by the buttons
#define PIN_1 21
#define PIN_2 20
#define PIN_3 19
#define PIN_4 18
#define PIN_5 15
#define PIN_6 14
#define PIN_7 16
#define PIN_8 10
#endif

// Pins used by the LEDs
#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5
#define LED_5 6
#define LED_6 7
#define LED_7 8
#define LED_8 9

// Some user-made colors
#define RED     strip.Color(255,0,0)
#define BLUE    strip.Color(0,0,255)
#define GREEN   strip.Color(0,255,0)
#define PURPLE  strip.Color(255,0,255)
#define YELLOW  strip.Color(255,255,0)
#define CYAN    strip.Color(0,255,255)
#define WHITE   strip.Color(255,255,255)
#define ORANGE  strip.Color(255,63,0)

// Debouncing declaration
Bounce button[NUMKEYS];

// Neopixel declaration
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

// Time and counter variables
uint32_t prevMillis = 0, curMillis = 0, delay_ms = 10;
uint16_t i = 0, j = 0;

// Status variables
uint8_t keyIsPressed = 0, keyPressed = 0xff, prevKey = 0;

// Arrays used for the for-loop sections of the program
const byte pinArray[NUMKEYS] = {PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7, PIN_8}; // 
const byte keyArray[NUMKEYS] = {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8};
const byte ledArray[NUMKEYS] = {LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8};
const byte neoPixelArray[2][4] = {{2,3,4,5},{0,1,6,7}};
const uint32_t colorArray[NUMKEYS] = {RED, BLUE, GREEN, PURPLE, YELLOW, CYAN, WHITE, ORANGE};

/*
 * @brief   Calculate rainbow colour based on 8-bit value
 * @param   Unsigned 8-bit number 
 * @returns None
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
void setColor(uint32_t color){
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
void startAnimation(uint32_t wait){

  // Flash the Underglow
  for(uint8_t i = 0; i < NUMKEYS; i++){
    setColor(colorArray[i]);
    strip.show();
    delay(wait);
  }

  // Flash the LEDs
  for(uint8_t j=0; j< NUMKEYS; j++) {
    digitalWrite(ledArray[j], HIGH);
    delay(wait/2);
  }
}

/**
 * @brief   Perform the main LED animation
 * @param   None
 * @returns None
 */
void mainAnimation(){

  switch(keyPressed){

    // If keypad is not pressed, do background animation
    case 0xff:
      if((curMillis - prevMillis) < EFFECT_DELAY_MS){
        return;
      }
      
      prevMillis = curMillis;
    
      for(i=0; i< strip.numPixels(); i++) {
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
        case 0:
          setColor(YELLOW);
        break;
            
        case 1:
          setColor(PURPLE);
        break;
            
        case 2:
          setColor(ORANGE);
        break;
            
        case 3:
          setColor(RED);
        break;
            
        case 4:
          setColor(GREEN);
        break;
            
        case 5:
          setColor(BLUE);
        break;
            
        case 6:
          setColor(WHITE);
        break;
            
        case 7:
          setColor(CYAN);
        break;
    #endif
         
    default:
    break;
  }
}

/**
 * @brief   Store event for button press into a variable
 * @param   0 or 1 for buttonIsPressed, 0-7 for buttonPressed
 * @return  None
 */
void buttonEvent(uint8_t buttonIsPressed, uint8_t buttonPressed){
  keyIsPressed = buttonIsPressed;
  keyPressed = buttonPressed;
}

/**
 * @brief   Scan buttons using for-loop
 * @param   None
 * @returns None
 */
void buttonScan(){
  // Scan the buttons and press macros if needed
  for(i=0; i < NUMKEYS; i++) {
    button[i].update();
   
    if(button[i].fell()){
      Keyboard.press(keyArray[i]);
      buttonEvent(1, i);
    }
    if(button[i].rose()){
      Keyboard.release(keyArray[i]);
      buttonEvent(0, 0xff);    
    }
  }  
}

/**
 * @brief   Scan buttons with individual set of if-statements; ideal for multi-key macros
 * @param   None
 * @returns None
 */
void buttonScan2(){
  // Scan the buttons and press macros if needed
  for(i=0; i < NUMKEYS; i++) {
    button[i].update();
  }  

  // SW1 
  if(button[0].fell()){
    Keyboard.press('a');
    buttonEvent(1, 0);    
  }
  if(button[0].rose()){
    Keyboard.release('a');
    buttonEvent(0, 0xff);
  }

  // SW2
  if(button[1].fell()){
    Keyboard.press('s');
    buttonEvent(1, 1);    
  }
  if(button[1].rose()){
    Keyboard.release('s');
    buttonEvent(0, 0xff);
  }
  
  // SW3
  if(button[2].fell()){
    Keyboard.press('d');
    buttonEvent(1, 2);    
  }
  if(button[2].rose()){
    Keyboard.release('d');
    buttonEvent(0, 0xff);
  }
  
  // SW4
  if(button[3].fell()){
    Keyboard.press(KEY_ESC);
    buttonEvent(1, 3);    
  }
  if(button[3].rose()){
    Keyboard.release(KEY_ESC);
    buttonEvent(0, 0xff);
  }
  
  // SW5
  if(button[4].fell()){
    Keyboard.press('z');
    buttonEvent(1, 4);    
  }
  if(button[4].rose()){
    Keyboard.release('z');
    buttonEvent(0, 0xff);
  }
  
  // SW6
  if(button[5].fell()){
    Keyboard.press('x');
    buttonEvent(1, 5);    
  }  
  if(button[5].rose()){
    Keyboard.release('x');
    buttonEvent(0, 0xff);
  }
  
  // SW7
  if(button[6].fell()){
    Keyboard.press('c');
    buttonEvent(1, 6);    
  }
  if(button[6].rose()){
    Keyboard.release('c');
    buttonEvent(0, 0xff);
  }
  
  // SW8
  if(button[7].fell()){
    Keyboard.press('v');
    buttonEvent(1, 7);    
  }
  if(button[7].rose()){
    Keyboard.release('v');
    buttonEvent(0, 0xff);
  }
}

/**
 * @brief   Main Program
 * @param   None
 * @return  None
 */
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
  startAnimation(125);
  
  // Initialize keyboard functions
  Keyboard.begin();
}

void loop() {
  curMillis = millis();
  prevKey = keyPressed;
 
  // Always scan buttons
  #ifdef SIMPLE_MODE
    buttonScan();
  #endif

  #ifdef MULTIKEY_MODE
    buttonScan2();
  #endif
  mainAnimation();

}
