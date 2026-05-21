#include "LedControl.h"  // library that we need for this sketch and the MAX7219.
typedef uint8_t byte;
LedControl lc = LedControl(11, 9, 10, 1);

byte smileyA1[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

#define buzzer 2 // Define the buzzer pin
#define buttonA1pin 3  //Define the push button A1 pin
#define buttonA2pin 4  //Define the push button A2 pin
#define buttonB1pin 5  //Define the push button B1 pin
#define buttonB2pin 6  //Define the push button B2 pin

byte screenBuffer[8];
int currentScreen = 0;
// 0 - loading
// 1 - ready
// 2 - edit

int loadingTime = 0;
int loadingDelay = 25; //Amount of loading ticks
const byte circleX[8] = {3, 4, 5, 5, 4, 3, 2, 2};
const byte circleY[8] = {2, 2, 3, 4, 5, 5, 4, 3};

int isLoading(){
  return currentScreen == 0;
}

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);


  lc.shutdown(0, false);
  lc.setIntensity(0, 0);

  pinMode(buzzer, OUTPUT);
  pinMode(buttonA1pin, INPUT);
  pinMode(buttonA2pin, INPUT);
  pinMode(buttonB1pin, INPUT);
  pinMode(buttonB2pin, INPUT);
}

void loop() {

  if(!isLoading()){
    checkBtnStates();
  }

  rerender();
  delay(100);
}
