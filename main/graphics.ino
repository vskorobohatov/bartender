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
  const byte startX = 2;
  const byte startY = 2;

  int totalTicks = 0;
  int ticksLeft = 0;

  if (isPumpAWorking) {
    totalTicks = pumpATotalTicks;
    ticksLeft = pumpATicksLeft;
  } else if (isPumpBWorking) {
    totalTicks = pumpBTotalTicks;
    ticksLeft = pumpBTicksLeft;
  }

  if (totalTicks > 0) {
    int pixelsToDraw = (ticksLeft * 16 + totalTicks - 1) / totalTicks;

    if (pixelsToDraw > 16) pixelsToDraw = 16;
    if (pixelsToDraw < 0) pixelsToDraw = 0;

    int drawn = 0;

    for (byte y = 0; y < 4; y++) {
      for (byte x = 0; x < 4; x++) {
        if (drawn < pixelsToDraw) {
          screenBuffer[startY + y] |= (1 << (startX + x));
        }
        drawn++;
      }
    }
  }
}

void generateMainScreen() {
  clearScreen();

  screenBuffer[0] = B01000010;
  screenBuffer[7] = B01000010;

  if (isBtnTopLeftPressed()) {
    screenBuffer[0] = B01000000;
  }
  if (isBtnBottomLeftPressed()) {
    screenBuffer[0] = B00000010;
  }

  if (isBtnTopRightPressed()) {
    screenBuffer[7] = B01000000;
  }

  if (isBtnBottomRightPressed()) {
    screenBuffer[7] = B00000010;
  }

  if (isPumping()) {
    renderPumpProcess();
  }
}

void generateEditScreen() {
  clearScreen();

  screenBuffer[0] = B01000010;
  screenBuffer[2] = B00111100;
  screenBuffer[3] = B00111100;
  screenBuffer[4] = B00111100;
  screenBuffer[5] = B00111100;
  screenBuffer[7] = B01000010;
}