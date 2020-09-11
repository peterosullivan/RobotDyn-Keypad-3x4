#include <Arduino.h>

#define KEYPAD_ANALOG_PIN A0

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
#define BUTTON_KEY9 KEY_F1
#define BUTTON_KEY10 KEY_F2
#define BUTTON_KEY11 KEY_F3
#define BUTTON_KEY12 KEY_F4

#define BUTTON_1 1023
#define BUTTON_2 931
#define BUTTON_3 853

#define BUTTON_4 783
#define BUTTON_5  728
#define BUTTON_6  679

#define BUTTON_7  635
#define BUTTON_8  597
#define BUTTON_9  565

#define BUTTON_10 532
#define BUTTON_11 506
#define BUTTON_12 482

// button detection
int get_button()
{
  // get A1 analog input value
  int val = analogRead(KEYPAD_ANALOG_PIN);
  if (val >= BUTTON_1) return 1;
  else if (val >= BUTTON_2) return 2;
  else if (val >= BUTTON_3) return 3;
  else if (val >= BUTTON_4) return 4;
  else if (val >= BUTTON_5) return 5;
  else if (val >= BUTTON_6) return 6;
  else if (val >= BUTTON_7) return 7;
  else if (val >= BUTTON_8) return 8;
  else if (val >= BUTTON_9) return 9;
  else if (val >= BUTTON_10) return 10;
  else if (val >= BUTTON_11) return 11;
  else if (val >= BUTTON_12) return 12;
  else return 0;
}

void setup(){
  Serial.begin(9600);
}

void loop(){
  // is any button pressed?
  int valueA1 = get_button();
  if (valueA1 > 0){
    Serial.print("Click button ");
    Serial.print(valueA1);
    Serial.print(" ");
    Serial.println(analogRead(KEYPAD_ANALOG_PIN));
    delay(200);
  }
}
