int isBtnTopLeftPressed() {
  return digitalRead(buttonA1pin) == HIGH;
}

int isBtnBottomLeftPressed() {
  return digitalRead(buttonA2pin) == HIGH;
}

int isBtnTopRightPressed() {
  return digitalRead(buttonB1pin) == HIGH;
}

int isBtnBottomRightPressed() {
  return digitalRead(buttonB2pin) == HIGH;
}

void checkBtnStates() {


  if (currentScreen == 1) {

    long currentMs = millis();

    if (isBtnTopLeftPressed() || btnA1MsStart != 0) {
      if (btnA1MsStart == 0) {
        btnA1MsStart = currentMs;
      } else if (isBtnTopLeftPressed() && currentMs - btnA1MsStart > 3000) {
        currentScreen = 2;
        buttonToEdit = 1;
        btnA1MsStart = 0;
      } else if (!isBtnTopLeftPressed()) {
        playSound(50);
        isPumpAWorking = true;
        pumpATicksLeft = settings.durationA1;
        pumpATotalTicks = settings.durationA1;
        btnA1MsStart = 0;
      }
    }

    if (isBtnBottomLeftPressed() || btnA2MsStart != 0) {
      if (btnA2MsStart == 0) {
        btnA2MsStart = currentMs;
      } else if (isBtnBottomLeftPressed() && currentMs - btnA2MsStart > 3000) {
        currentScreen = 2;
        buttonToEdit = 1;
        btnA2MsStart = 0;
      } else if (!isBtnBottomLeftPressed()) {
        playSound(50);
        isPumpAWorking = true;
        pumpATicksLeft = settings.durationA2;
        pumpATotalTicks = settings.durationA2;
        btnA2MsStart = 0;
      }
    }

    if (isBtnTopRightPressed() || btnB1MsStart != 0) {
      if (btnB1MsStart == 0) {
        btnB1MsStart = currentMs;
      } else if (isBtnTopRightPressed() && currentMs - btnB1MsStart > 3000) {
        currentScreen = 2;
        buttonToEdit = 2;
        btnB1MsStart = 0;
      } else if (!isBtnTopRightPressed()) {
        playSound(50);
        isPumpBWorking = true;
        pumpBTicksLeft = settings.durationB1;
        pumpBTotalTicks = settings.durationB1;
        btnB1MsStart = 0;
      }
    }

    if (isBtnBottomRightPressed() || btnB2MsStart != 0) {
      if (btnB2MsStart == 0) {
        btnB2MsStart = currentMs;
      } else if (isBtnBottomRightPressed() && currentMs - btnB2MsStart > 3000) {
        currentScreen = 2;
        buttonToEdit = 3;
        btnB2MsStart = 0;
      } else if (!isBtnBottomRightPressed()) {
        playSound(50);
        isPumpBWorking = true;
        pumpBTicksLeft = settings.durationB2;
        pumpBTotalTicks = settings.durationB2;
        btnB2MsStart = 0;
      }
    }
  }
}