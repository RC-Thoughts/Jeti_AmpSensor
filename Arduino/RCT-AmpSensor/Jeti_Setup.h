//
// Stuff that needs to be inside void setup()
//

/* Sensor Name
  Serial speed is 10240 for Pro Mini 3.3V due software serial
  Serial speed is 9800 for Pro Mini 5V due software serial */
JB.Init(F("RCT Amp"), JETI_RX, 9800);

// Pinmode for reset
pinMode(pinReset, INPUT_PULLUP);

// Calibration settings - Reset to defaults on first use of Arduino Pro Mini
if (EEPROM.read(0) != 1) {
  EEPROM.write(0, 1); // Reset byte set to done
  EEPROM.write(1, 0); // Reset-function, not in use = 0, in use = 1
  EEPROM.write(2, 0); // Sensor type, default is Not Set
  EEPROM.write(3, 0); // Voltage range, default is 14S 60V
  EEPROM.write(4, 100); // Calibration value for current, default is 100, displayed as 0 in Jetibox
  EEPROM.put(10, 0);  // Saved capacity (mAh)
}

// Read settings
resetFunction = EEPROM.read(1);
sensorType = EEPROM.read(2);
voltageRange = EEPROM.read(3);
curCalVal = EEPROM.read(4);
if (resetFunction == 1) {
  EEPROM.get(10, uCapacity);
}

// Running values
mVperAmp = mVperAmpArray[sensorType];
ACSoffset = ACSoffsetArray[sensorType];
dividerR1 = R1[voltageRange];
dividerR2 = R2[voltageRange];
tempcurCalVal = curCalVal - 100;

// Calculate voltage divider
divider = (float)dividerR2 / (dividerR1 + dividerR2);

/*
  Define Jeti Sensor value name & unit & variable & precision (decimals)
  JB.setValue30(JB.addData(F("NAME"), F("UNIT")), &VARIABLE, DEC);

  Sensor-value ranges:
  JB.setValue6 =   -31 to 31               (Variable is uint8_t)
  JB.setValue14 =  -8191 to 8191           (Variable is int)
  JB.setValue30 =  -536870911 to 536870911 (Variable is long)
*/

JB.setValue30(JB.addData(F("Current"), F("A")), &jetiCurrent, 1);
JB.setValue30(JB.addData(F("Capacity"), F("mAh")), &uCapacity, 0);
JB.setValue30(JB.addData(F("Voltage"), F("V")), &jetiVoltage, 2);
JB.setValue30(JB.addData(F("Power"), F("W")), &uPower, 0);
