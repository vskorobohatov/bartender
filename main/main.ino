#include "LedControl.h"  // library that we need for this sketch and the MAX7219.
#include <EEPROM.h>


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

// Define your data structure
struct MySettings {
  int flag;
  int durationA1;
  int durationA2;
  int durationB1;
  int durationB2;
};

#define buzzer 2       // Define the buzzer pin
#define buttonA1pin 3  //Define the push button A1 pin
#define buttonA2pin 4  //Define the push button A2 pin
#define buttonB1pin 5  //Define the push button B1 pin
#define buttonB2pin 6  //Define the push button B2 pin
#define pumpA 7       // Define the pump 1 pin
#define pumpB 8       // Define the pump 2 pin
#define defaultFlagValue 111

// Screen states
byte screenBuffer[8];
int currentScreen = 0;
// 0 - loading
// 1 - ready
// 2 - edit

// Pumps states
int pumpTickDuration = 50;
bool isPumpAWorking = false;
int pumpATicksLeft = 0;
bool isPumpBWorking = false;
int pumpBTicksLeft = 0;

// Loading states
int loadingTime = 0;
int loadingDelay = 25;

MySettings settings = { defaultFlagValue, 10, 10, 10, 10 };

int isLoading() {
  return currentScreen == 0;
}

int isPumping() {
  return isPumpAWorking || isPumpBWorking;
}

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  MySettings loadedSettings;
  EEPROM.get(0, loadedSettings);

  if (loadedSettings.flag != defaultFlagValue) { // Check saved settings.
    EEPROM.put(0, settings); 
  } else {
    settings = loadedSettings;
  }

  Serial.print("Settings flag: ");
  Serial.println(settings.flag);
  Serial.print("Settings durationA1: ");
  Serial.println(settings.durationA1);
  Serial.print("Settings durationA2: ");
  Serial.println(settings.durationA2);
  Serial.print("Settings durationB1: ");
  Serial.println(settings.durationB1);
  Serial.print("Settings durationB2: ");
  Serial.println(settings.durationB2);
  //settings.durationA1++;
  //  EEPROM.put(0, settings); 

  lc.shutdown(0, false);
  lc.setIntensity(0, 0);

  pinMode(buzzer, OUTPUT);
  pinMode(pumpA, OUTPUT);
  pinMode(pumpB, OUTPUT);
  pinMode(buttonA1pin, INPUT);
  pinMode(buttonA2pin, INPUT);
  pinMode(buttonB1pin, INPUT);
  pinMode(buttonB2pin, INPUT);
}

void loop() {
  if (!isLoading() && !isPumping()) {
    checkBtnStates();
  }

  if(isPumping()){
    if(pumpATicksLeft > 0){
      pumpWater(pumpA);
      pumpATicksLeft--;
    }else{
      isPumpAWorking = false;
    }
    if(pumpBTicksLeft > 0){
      pumpWater(pumpB);
      pumpBTicksLeft--;
    }else{
      isPumpBWorking = false;
    }
  }

  rerender();
  delay(100);
}
