void clearScreen(){
    for (int i = 0; i < 8; i++){
        screenBuffer[i] = 0;
    }
}

void renderScreen() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, screenBuffer[i]);
  }
}

void rerender(){
  if(currentScreen == 0){
    if(loadingTime < loadingDelay){
      generateLoadingFrame();
      loadingTime++;
    } else {
      clearScreen();
      currentScreen = 1;
    }
  }
  if(currentScreen == 1){
    generateMainScreen();
  }
  renderScreen();
}

byte* generateLoadingFrame(){
    static byte frame = 0;
    
    clearScreen();
    
    byte x = circleX[frame];
    byte y = circleY[frame];

    screenBuffer[y] |= (1 << (7 - x));
    
    frame++;
    
    if (frame >= 8){
        frame = 0;
    }
}

byte* generateMainScreen(){
    clearScreen();
    
    if (!isBtnTopLeftPressed()){
        screenBuffer[0] |= (1 << 1);
    }

    if (!isBtnTopRightPressed()){
        screenBuffer[0] |= (1 << 6);
    }

    if (!isBtnBottomLeftPressed()){
        screenBuffer[7] |= (1 << 1);
    }

    if (!isBtnBottomRightPressed()){
        screenBuffer[7] |= (1 << 6);
    }
}