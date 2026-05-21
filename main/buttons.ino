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