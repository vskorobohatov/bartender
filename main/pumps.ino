void pumpWater(int pumpN){
  digitalWrite(pumpN, LOW);
  delay(pumpTickDuration);
  digitalWrite(pumpN, HIGH);
}