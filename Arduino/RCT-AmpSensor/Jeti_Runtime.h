//
// This is the main loop where the work is done
// May the current be with you
//

if (sensorType != 0) {
  // Calculate voltage (V)
  uVoltage = (analogRead(analogInVolt) / 1023.0) * (5010 / 1000) / divider * (voltCalVal / 1000.0);

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
    tmpCap = 0;
    curMillis = millis() - prevMillis;
    tmpCap = tmpCap + (uCurrent * 1000.0) * ((float)curMillis / 3600000.0);
    uCapacity = uCapacity + tmpCap;
    prevMillis = millis();
  }

  // If reset-function is in use set timer if current is over 1A
  if (resetFunction == 1 && uCurrent > 1) {
    currentActive = 1;
    currentStored = 0;
    resetTime = millis() + 15000;
    digitalWrite(13, LOW);
  } else {
    currentActive = 0;
  }

  // If reset-function is in use and if no current consumed for 15 seconds store consumed capacity once to EEPROM
  curTime = millis();
  if (resetFunction == 1 && currentActive == 0 && currentStored == 0 && curTime > resetTime && ((int)uCapacity > 0)) {
    writeEEPROM(20, (int)uCapacity);
    currentStored = 1;
    digitalWrite(13, HIGH);
  }

  // If reset-function is in use reset consumed capacity from Digital Output
  // allowed only if there is no current used! (Motor off)
  if (resetFunction == 1) {
    resetState = digitalRead(pinReset); // HIGH when open, LOW when closed to GND
    if (currentActive == 0 && resetState == LOW) {
      writeEEPROM(20, 0);
      currentStored = 1;
      uCapacity = 0;
      digitalWrite(13, LOW);
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
jetiCapacity = (long)uCapacity;
