#include <Arduino.h>

#define KEYPAD_ANALOG_PIN A3

//Gytis_Orz sketch from Hackster.io more info https://www.hackster.io/Gytis_Orz/macro-keypad-02cb43
// Wiring:
// VCC -> 5V
// GND -> GND
// OUT -> A0 (Analog 0)
#include <Keyboard.h>

#define BUTTON_KEY1 KEY_F13
#define BUTTON_KEY2 KEY_F14
#define BUTTON_KEY3 KEY_F15
#define BUTTON_KEY4 KEY_F16
#define BUTTON_KEY5 KEY_F17
#define BUTTON_KEY6 KEY_F18
#define BUTTON_KEY7 KEY_F19
#define BUTTON_KEY8 KEY_F20
#define BUTTON_KEY9 KEY_F21
#define BUTTON_KEY10 KEY_F22
#define BUTTON_KEY11 KEY_F23
#define BUTTON_KEY12 KEY_F24

#define BUTTON_1  1023
#define BUTTON_2  931
#define BUTTON_3  853

#define BUTTON_4  783
#define BUTTON_5  728
#define BUTTON_6  679

#define BUTTON_7  635
#define BUTTON_8  597
#define BUTTON_9  565

#define BUTTON_10 532
#define BUTTON_11 506
#define BUTTON_12 482

// button detection
int get_button(){

  int value = analogRead(KEYPAD_ANALOG_PIN);

  if (value >= BUTTON_1)       return BUTTON_KEY1;
  else if (value >= BUTTON_2)  return BUTTON_KEY2;
  else if (value >= BUTTON_3)  return BUTTON_KEY3;
  else if (value >= BUTTON_4)  return BUTTON_KEY4;
  else if (value >= BUTTON_5)  return BUTTON_KEY5;
  else if (value >= BUTTON_6)  return BUTTON_KEY6;
  else if (value >= BUTTON_7)  return BUTTON_KEY7;
  else if (value >= BUTTON_8)  return BUTTON_KEY8;
  else if (value >= BUTTON_9)  return BUTTON_KEY9;
  else if (value >= BUTTON_10) return  BUTTON_KEY10;
  else if (value >= BUTTON_11) return  BUTTON_KEY11;
  else if (value >= BUTTON_12) return  BUTTON_KEY12;
  else return 0;
}

void failsafe(){
  for (;;){
  } // Just going to hang out here for awhile :D
}

void setup(){
  //Serial.begin(9600);

  // Safety check. Ground pin #1 (RX) to cancel keyboard inputs.
  pinMode(1, INPUT_PULLUP);
  if (!digitalRead(1)){
    failsafe();
  }
}

void loop(){
  // is any button pressed?
  int key = get_button();
  if (key > 0){
    
    //Serial.println(analogRead(KEYPAD_ANALOG_PIN));
    //Serial.print(key);

    Keyboard.write(key);
    //Keyboard.press(key);
    //Keyboard.release(key);

    delay(100);
  }
}
