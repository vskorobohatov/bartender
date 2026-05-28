void clearScreen() {
  for (int i = 0; i < 8; i++) {
    screenBuffer[i] = 0;
  }
}

void renderScreen() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, screenBuffer[i]);
  }
}

void rerender() {
  if (currentScreen == 0) {
    if (loadingTime < loadingDelay) {
      generateLoadingFrame();
      loadingTime++;
    } else {
      clearScreen();
      currentScreen = 1;
    }
  }
  if (currentScreen == 1) {
    generateMainScreen();
  }
  if (currentScreen == 2) {
    generateEditScreen();
  }
  renderScreen();
}

byte* generateLoadingFrame() {
  const byte circleX[8] = { 3, 4, 5, 5, 4, 3, 2, 2 };
  const byte circleY[8] = { 2, 2, 3, 4, 5, 5, 4, 3 };
  static byte frame = 0;

  clearScreen();

  byte x = circleX[frame];
  byte y = circleY[frame];

  screenBuffer[y] |= (1 << (7 - x));

  frame++;

  if (frame >= 8) {
    frame = 0;
  }
}

void renderPumpProcess() {
  if (isPumpAWorking) {
    renderSquare(pumpATicksLeft);
  } else if (isPumpBWorking) {
    renderSquare(pumpBTicksLeft);
  }
}

void renderSquare(int totalCount) {
  const byte startX = 2;
  const byte startY = 2;
  int drawn = 0;
  int total = totalCount;
  Serial.print(totalCount);


  for (byte x = 0; x < 4; x++) {
    for (byte y = 0; y < 4; y++) {
      if (drawn < total) {
        screenBuffer[startY + y] |= (1 << (startX + x));
      }
      drawn++;
    }
  }
}

void renderButtonsIndicators() {
  screenBuffer[0] = B01000010;
  screenBuffer[7] = B01000010;

  if (isBtnTopLeftPressed()) {
    screenBuffer[7] = B00000010;
  }
  if (isBtnBottomLeftPressed()) {
    screenBuffer[7] = B01000000;
  }

  if (isBtnTopRightPressed()) {
    screenBuffer[0] = B00000010;
  }

  if (isBtnBottomRightPressed()) {
    screenBuffer[0] = B01000000;
  }
}

void generateMainScreen() {
  clearScreen();

  renderButtonsIndicators();

  if (isPumping()) {
    renderPumpProcess();
  }
}

void generateEditScreen() {
  clearScreen();

  renderButtonsIndicators();

  switch (buttonToEdit) {
    case 1:
      renderSquare(settings.durationA1);
      break;
    case 2:
      renderSquare(settings.durationA2);
      break;
    case 3:
      renderSquare(settings.durationB1);
      break;
    case 4:
      renderSquare(settings.durationB2);
      break;
  }
}