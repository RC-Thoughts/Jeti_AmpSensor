//
// Build Jetibox screens
//

case 0 : { // aboutScreen
  JB.JetiBox_P(ABOUT_1, ABOUT_2);
  break;
}
case 1 : { // viewCurrentCapacity
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Cur: "));
  temp[0] = 0;
  floatToString((char*)&temp, uCurrent, 1);
  strcat((char*)&msg_line1, (char*)&temp);
  strcat_P((char*)&msg_line1, (const char*)F("A"));
  strcat_P((char*)&msg_line2, (const char*)F("Cap: "));
  temp[0] = 0;
  floatToString((char*)&temp, uCapacity, 0);
  strcat((char*)&msg_line2, (char*)&temp);
  strcat_P((char*)&msg_line2, (const char*)F("mAh"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 2 : { // viewVoltagePower
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Voltage: "));
  temp[0] = 0;
  floatToString((char*)&temp, uVoltage, 2);
  strcat((char*)&msg_line1, (char*)&temp);
  strcat_P((char*)&msg_line1, (const char*)F("V"));
  strcat_P((char*)&msg_line2, (const char*)F("Power:   "));
  temp[0] = 0;
  floatToString((char*)&temp, uPower, 0);
  strcat((char*)&msg_line2, (char*)&temp);
  strcat_P((char*)&msg_line2, (const char*)F("W"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 3 : { // setSensorType
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Set Sensor Type:"));
  if (sensorType == 0) {
    strcat_P((char*)&msg_line2, (const char*)F(" Sensor Not Set"));
  }
  if (sensorType == 1) {
    strcat_P((char*)&msg_line2, (const char*)F("  ACS712-05"));
  }
  if (sensorType == 2) {
    strcat_P((char*)&msg_line2, (const char*)F("  ACS712-20"));
  }
  if (sensorType == 3) {
    strcat_P((char*)&msg_line2, (const char*)F("  ACS712-30"));
  }
  if (sensorType == 4) {
    strcat_P((char*)&msg_line2, (const char*)F("  ACS758-50B"));
  }
  if (sensorType == 5) {
    strcat_P((char*)&msg_line2, (const char*)F("  ACS758-100B"));
  }
  if (sensorType == 6) {
    strcat_P((char*)&msg_line2, (const char*)F("  ACS758-150B"));
  }
  if (sensorType == 7) {
    strcat_P((char*)&msg_line2, (const char*)F("  ACS758-200B"));
  }
  if (sensorType == 8) {
    strcat_P((char*)&msg_line2, (const char*)F("  ACS758-50U"));
  }
  if (sensorType == 9) {
    strcat_P((char*)&msg_line2, (const char*)F("  ACS758-100U"));
  }
  if (sensorType == 10) {
    strcat_P((char*)&msg_line2, (const char*)F("  ACS758-150U"));
  }
  if (sensorType == 11) {
    strcat_P((char*)&msg_line2, (const char*)F("  ACS758-200U"));
  }
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 4 : { // setVoltageDivider
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Set Max. Voltage"));
  if (voltageRange == 0) {
    strcat_P((char*)&msg_line2, (const char*)F("  Max. 14S 60V"));
  }
  if (voltageRange == 1) {
    strcat_P((char*)&msg_line2, (const char*)F("  Max. 6S 30V"));
  }
  if (voltageRange == 2) {
    strcat_P((char*)&msg_line2, (const char*)F("  Max. 3S 15V"));
  }
  if (voltageRange == 3) {
    strcat_P((char*)&msg_line2, (const char*)F("  Max. 2S/Rx 10V"));
  }
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 5 : { // currentCalibration
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Current: "));
  temp[0] = 0;
  floatToString((char*)&temp, uCurrent, 2);
  strcat((char*)&msg_line1, (char*)&temp);
  strcat_P((char*)&msg_line1, (const char*)F("A"));
  strcat_P((char*)&msg_line2, (const char*)F("Calibration: "));
  temp[0] = 0;
  tempcurCalVal = curCalVal - 100;
  floatToString((char*)&temp, tempcurCalVal, 0);
  strcat((char*)&msg_line2, (char*)&temp);
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 6 : { // voltageCalibration
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Voltage: "));
  temp[0] = 0;
  floatToString((char*)&temp, uVoltage, 2);
  strcat((char*)&msg_line1, (char*)&temp);
  strcat_P((char*)&msg_line1, (const char*)F("V"));
  strcat_P((char*)&msg_line2, (const char*)F("Calibration: "));
  temp[0] = 0;
  tempvoltCalVal = voltCalVal - 1000;
  floatToString((char*)&temp, tempvoltCalVal, 0);
  strcat((char*)&msg_line2, (char*)&temp);
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 7 : { // useReset
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Dig.Reset: "));
  if (resetFunction == 0) {
    strcat_P((char*)&msg_line1, (const char*)F("No"));
  }
  if (resetFunction == 1) {
    strcat_P((char*)&msg_line1, (const char*)F("Yes"));
  }
  strcat_P((char*)&msg_line2, (const char*)F("Change Dn Next >"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 8 : { // storeSettings
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Reset or Save"));
  strcat_P((char*)&msg_line2, (const char*)F("Rst UpDn Save >"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case MAX_SCREEN : {
  JB.JetiBox_P(ABOUT_1, ABOUT_2);
  break;
}
