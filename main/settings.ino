
void loadSavedSettings(){
  MySettings loadedSettings;
  EEPROM.get(0, loadedSettings);

  if (loadedSettings.flag != defaultFlagValue) { // Check saved settings.
    EEPROM.put(0, settings); 
  } else {
    settings = loadedSettings;
  }
}

void saveSettings(){
  EEPROM.put(0, settings);
}