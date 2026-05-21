void clearScreen(){
    for (int i = 0; i < 8; i++){
        screenData[i] = 0;
    }
}

void renderScreen() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, screenData[i]);
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
    
  }
  renderScreen();
}

byte* generateLoadingFrame(){
    static byte frame = 0;
    
    clearScreen();
    
    byte x = circleX[frame];
    byte y = circleY[frame];

    screenData[y] |= (1 << (7 - x));
    
    frame++;
    
    if (frame >= 8){
        frame = 0;
    }
}

byte* generateReadyFrame(){
    static byte frame = 0;
    
    clearScreen();

    screenData[y] |= (1 << (7 - x));
    
    frame++;
    
    if (frame >= 8){
        frame = 0;
    }
}