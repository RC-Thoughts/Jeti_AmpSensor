//
// Jetibox navigation and button actions
//
/*
  Button codes
  224  RIGHT
  112  LEFT
  208  UP
  176  DOWN
  144  UP & DOWN
  9    LEFT & RIGHT
*/
case 224 : // RIGHT
if (current_screen != MAX_SCREEN)
{
  if (current_screen == 9) {
    EEPROM.write(0, 1); // Reset byte set to done
    EEPROM.write(1, resetFunction); // Reset-function, not in use = 0, in use = 1
    EEPROM.write(2, sensorType); // Sensor type, default is Not Set
    EEPROM.write(3, voltageRange); // Voltage range, default is 14S 60V
    EEPROM.write(4, curCalVal); // Calibration value for current, default is 100
    EEPROM.put(10, voltCalVal); // Calibration value for voltage, default is 100
    EEPROM.put(20, 0);  // Saved capacity (mAh)
    delay(200);
    resetSensor();
  } else {
    current_screen++;
  }
}
break;

case 112 : // LEFT
if (current_screen == 99) {
  current_screen = 0;
}
if (current_screen != 0) {
  current_screen--;
}
break;

case 208 : // UP
if (current_screen == 3) {
  if (sensorType < 12) sensorType++;
  if (sensorType == 12) sensorType = 0;
}
if (current_screen == 4) {
  if (voltageRange < 4) voltageRange++;
  if (voltageRange == 4) voltageRange = 0;
}
if (current_screen == 5) {
  curCalVal++;
}
if (current_screen == 6) {
  voltCalVal++;
}
if (current_screen == 7) {
  if (resetFunction == 0) {
    resetFunction = 1;
  } else {
    resetFunction = 0;
  }
}
break;

case 176 : // DOWN
if (current_screen == 3) {
  if (sensorType == 0) sensorType = 12;
  if (sensorType > 0) sensorType--;
}
if (current_screen == 4) {
  if (voltageRange < 4) voltageRange++;
  if (voltageRange == 4) voltageRange = 0;
}
if (current_screen == 5) {
  curCalVal--;
}
if (current_screen == 6) {
  voltCalVal--;
}
if (current_screen == 7) {
  if (resetFunction == 0) {
    resetFunction = 1;
  } else {
    resetFunction = 0;
  }
}
break;

case 144 : // UP+DOWN
if (current_screen == 8) {
  EEPROM.write(0, 0); // Reset byte
  delay(200);
  resetSensor();
}
break;

case 96 : // LEFT+RIGHT
break;
