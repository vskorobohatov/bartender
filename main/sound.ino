void playSound(int duration){
  tone(buzzer, 1000);
  delay(duration);
  noTone(buzzer);
}