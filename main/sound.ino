void playSound(int freq){
  tone(buzzer, freq);
  delay(300);
  noTone(buzzer);
}