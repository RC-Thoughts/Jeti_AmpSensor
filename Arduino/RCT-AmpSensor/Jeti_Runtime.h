//
// This is the main loop where the work is done
// May the current be with you
//

if (sensorType != 0) {
  // Calculate voltage (V)
  uVoltage = (analogRead(analogInVolt) / 1023.0) * (5010 / 1000) / divider;

  // Calculate current (A)
  float mVoltCur = (analogRead(analogInCur) / 1023.0) * 5010; // mV
  uCurrent = (mVoltCur - ACSoffset + tempcurCalVal) / mVperAmp;
  if (uCurrent < 0) {
    uCurrent = 0;
  }

  // Calculate power (W)
  uPower = uCurrent * uVoltage;

  // mAh calculation 2 times a second
  if (millis() > prevMillis + 500) {
    curMillis = millis() - prevMillis;
    uCapacity = uCapacity + (uCurrent * 1000) * (curMillis / 3600000.0);
    prevMillis = millis();
  }

  // If reset-function is in use and fuel is flowing monitor fuel-flow and set timer
  if (resetFunction == 1 && uCurrent > 2) {
    currentActive = 1;
    currentStored = 0;
    resetTime = millis() + 15000; // If no current consumed 15 seconds timer to store value to EEPROM
  } else {
    currentActive = 0;
  }

  // If reset-function is in use and if no current consumed for 15 seconds store consumed capacity once to EEPROM
  curTime = millis();
  if (resetFunction == 1 && currentActive == 0 && currentStored == 0 && curTime > resetTime) {
    EEPROM.put(10, uCapacity);
    currentStored = 1;
  }

  // If reset-function is in use reset consumed capacity from Digital Output
  // allowed only if there is no current used! (Motor off)
  if (resetFunction == 1) {
    resetState = digitalRead(pinReset); // HIGH when open, LOW when closed to GND
    if (currentActive == 0 && resetState == LOW) {
      uCapacity = 0;
      EEPROM.put(10, uCapacity);
      currentStored = 1;
    }
  }
}
else {
  uVoltage = 0;
  uCurrent = 0;
  uPower = 0;
  uCapacity = 0;
}
jetiVoltage = uVoltage * 100;
jetiCurrent = uCurrent * 10;
