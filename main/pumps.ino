int isPumping() {
  return isPumpAWorking || isPumpBWorking;
}

void updatePumps() {
  if (isPumping()) {
    if (pumpATicksLeft > 0) {
      digitalWrite(pumpA, LOW);
      delay(pumpsTickDuration);
      digitalWrite(pumpA, HIGH);
      pumpATicksLeft--;
    } else {
      isPumpAWorking = false;
    }
    if (pumpBTicksLeft > 0) {
      digitalWrite(pumpB, LOW);
      delay(pumpsTickDuration);
      digitalWrite(pumpB, HIGH);
      pumpBTicksLeft--;
    } else {
      isPumpBWorking = false;
    }
  }
}