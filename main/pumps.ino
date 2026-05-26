void updatePumps() {
  if (isPumping()) {
    if (pumpATicksLeft > 0) {
      digitalWrite(pumpA, LOW);
      pumpATicksLeft--;
    } else {
      isPumpAWorking = false;
    }
    if (pumpBTicksLeft > 0) {
      digitalWrite(pumpB, LOW);
      pumpBTicksLeft--;
    } else {
      isPumpBWorking = false;
    }
  }
}