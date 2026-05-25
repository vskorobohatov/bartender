int isBtnTopLeftPressed(){
    return digitalRead(buttonA1pin) == HIGH;
}

int isBtnTopRightPressed(){
    return digitalRead(buttonA2pin) == HIGH;
}

int isBtnBottomLeftPressed(){
    return digitalRead(buttonB1pin) == HIGH;
}

int isBtnBottomRightPressed(){
    return digitalRead(buttonB2pin) == HIGH;
}

void checkBtnStates(){
    if(isBtnTopLeftPressed()){
        playSound(50);
        isPumpAWorking = true;
        pumpATicksLeft = settings.durationA1;
    }
    if(isBtnBottomLeftPressed()){
        playSound(50);
        isPumpAWorking = true;
        pumpATicksLeft = settings.durationA2;
    }
    if(isBtnTopRightPressed()){
        playSound(50);
        isPumpBWorking = true;
        pumpBTicksLeft = settings.durationB1;
    }
    if(isBtnBottomRightPressed()){
        playSound(50);
        isPumpBWorking = true;
        pumpBTicksLeft = settings.durationB2;
    }
}