int isBtnTopLeftPressed() {
  return digitalRead(buttonB2pin) == HIGH;
}

int isBtnBottomLeftPressed() {
  return digitalRead(buttonB1pin) == HIGH;
}

int isBtnTopRightPressed() {
  return digitalRead(buttonA2pin) == HIGH;
}

int isBtnBottomRightPressed() {
  return digitalRead(buttonA1pin) == HIGH;
}

void checkBtnStates() {


  if (currentScreen == 1 && !isPumping()) {

    long currentMs = millis();

    if (isBtnTopLeftPressed() || btnA1MsStart != 0) {
      if (btnA1MsStart == 0) {
        btnA1MsStart = currentMs;
      } else if (isBtnTopLeftPressed() && currentMs - btnA1MsStart > 3000) {
        currentScreen = 2;
        buttonToEdit = 1;
        btnA1MsStart = 0;
        playSound(50);
      } else if (!isBtnTopLeftPressed()) {
        isPumpAWorking = true;
        pumpATicksLeft = settings.durationA1;
        pumpATotalTicks = settings.durationA1;
        btnA1MsStart = 0;
        playSound(50);
      }
    }

    if (isBtnBottomLeftPressed() || btnA2MsStart != 0) {
      if (btnA2MsStart == 0) {
        btnA2MsStart = currentMs;
      } else if (isBtnBottomLeftPressed() && currentMs - btnA2MsStart > 3000) {
        currentScreen = 2;
        buttonToEdit = 2;
        btnA2MsStart = 0;
        playSound(50);
      } else if (!isBtnBottomLeftPressed()) {
        isPumpAWorking = true;
        pumpATicksLeft = settings.durationA2;
        pumpATotalTicks = settings.durationA2;
        btnA2MsStart = 0;
        playSound(50);
      }
    }

    if (isBtnTopRightPressed() || btnB1MsStart != 0) {
      if (btnB1MsStart == 0) {
        btnB1MsStart = currentMs;
      } else if (isBtnTopRightPressed() && currentMs - btnB1MsStart > 3000) {
        currentScreen = 2;
        buttonToEdit = 3;
        btnB1MsStart = 0;
        playSound(50);
      } else if (!isBtnTopRightPressed()) {
        isPumpBWorking = true;
        pumpBTicksLeft = settings.durationB1;
        pumpBTotalTicks = settings.durationB1;
        btnB1MsStart = 0;
        playSound(50);
      }
    }

    if (isBtnBottomRightPressed() || btnB2MsStart != 0) {
      if (btnB2MsStart == 0) {
        btnB2MsStart = currentMs;
      } else if (isBtnBottomRightPressed() && currentMs - btnB2MsStart > 3000) {
        currentScreen = 2;
        buttonToEdit = 4;
        btnB2MsStart = 0;
        playSound(50);
      } else if (!isBtnBottomRightPressed()) {
        isPumpBWorking = true;
        pumpBTicksLeft = settings.durationB2;
        pumpBTotalTicks = settings.durationB2;
        btnB2MsStart = 0;
        playSound(50);
      }
    }
  }

  if (currentScreen == 2) {
    if (isBtnTopLeftPressed()) {
      settingsWereChanged = true;
      playSound(50);

      switch (buttonToEdit) {
        case 1:
          if (settings.durationA1 < 16) {
            settings.durationA1++;
          }
          break;
        case 2:
          if (settings.durationA2 < 16) {
            settings.durationA2++;
          }
          break;
        case 3:
          if (settings.durationB1 < 16) {
            settings.durationB1++;
          }
          break;
        case 4:
          if (settings.durationB2 < 16) {
            settings.durationB2++;
          }
          break;
      }
    }

    if (isBtnBottomLeftPressed()) {
      settingsWereChanged = true;
      playSound(50);

      switch (buttonToEdit) {
        case 1:
          if (settings.durationA1 > 1) {
            settings.durationA1--;
          }
          break;
        case 2:
          if (settings.durationA2 > 1) {
            settings.durationA2--;
          }
          break;
        case 3:
          if (settings.durationB1 > 1) {
            settings.durationB1--;
          }
          break;
        case 4:
          if (settings.durationB2 > 1) {
            settings.durationB2--;
          }
          break;
      }
    }

    if (isBtnTopRightPressed()) {
      loadSavedSettings();
      playSound(50);
      delay(50);
      playSound(50);
    }

    if (isBtnBottomRightPressed() && settingsWereChanged) {
      saveSettings();
      currentScreen = 1;
      settingsWereChanged = false;
      playSound(50);
      delay(50);
      playSound(50);
      delay(1000);
    }
  }
}