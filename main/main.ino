#include "LedControl.h"  // library that we need for this sketch and the MAX7219.
typedef uint8_t byte;
LedControl lc = LedControl(11, 9, 10, 1);

byte smileyA1[] = {
  B00001111,
  B00001111,
  B00001111,
  B00001111,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte smileyA2[] = {
  B11110000,
  B11110000,
  B11110000,
  B11110000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte smileyB1[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00001111,
  B00001111,
  B00001111,
  B00001111
};

byte smileyB2[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11110000,
  B11110000,
  B11110000,
  B11110000
};

#define buttonA1pin 2  //Define the push button A1 pin
#define buttonA2pin 3  //Define the push button A2 pin
#define buttonB1pin 4  //Define the push button B1 pin
#define buttonB2pin 5  //Define the push button B2 pin

byte screenData[8];
int currentScreen = 0;
// 0 - loading
// 1 - ready
// 2 - edit

int loadingTime = 0;
int loadingDelay = 25; //Amount of loading ticks
const byte circleX[8] = {3, 4, 5, 5, 4, 3, 2, 2};
const byte circleY[8] = {2, 2, 3, 4, 5, 5, 4, 3};

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  lc.shutdown(0, false);
  lc.setIntensity(0, 0);

  pinMode(buttonA1pin, INPUT);
  pinMode(buttonA2pin, INPUT);
  pinMode(buttonB1pin, INPUT);
  pinMode(buttonB2pin, INPUT);
}

void loop() {

  int buttonA1val = digitalRead(buttonA1pin);  // check the state of the A1 button
  if (buttonA1val == HIGH) {
    Serial.println("Button A1 pressed!");
  } else {
    Serial.println("Button A1 not pressed!");
  }

  int buttonA2val = digitalRead(buttonA2pin);  // check the state of the A2 button
  if (buttonA2val == HIGH) {
    Serial.println("Button A2 pressed!");
  } else {
    Serial.println("Button A2 not pressed!");
  }

  int buttonB1val = digitalRead(buttonB1pin);  // check the state of the B1 button
  if (buttonB1val == HIGH) {
    Serial.println("Button B1 pressed!");
  } else {
    Serial.println("Button B1 not pressed!");
  }

  int buttonB2val = digitalRead(buttonB2pin);  // check the state of the B2 button
  if (buttonB2val == HIGH) {
    Serial.println("Button B2 pressed!");
  } else {
    Serial.println("Button B2 not pressed!");
  }


  // Wait for 100 ms
  rerender();
  delay(100);
}
