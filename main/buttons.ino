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
    if(isBtnBottomLeftPressed()){
        playSound(500);
    }
    if(isBtnBottomRightPressed()){
        playSound(1000);
    }
    if(isBtnTopLeftPressed()){
        playSound(700);
    }
    if(isBtnTopRightPressed()){
        playSound(300);
    }
}