//
// For any extra functions needed before loop()
//

void(* resetSensor) (void) = 0;

// Write used Capacity to EEPROM (MAX 32767mAh)
void writeEEPROM(int address, int number)
{ 
  EEPROM.write(address, number >> 8);
  EEPROM.write(address + 1, number & 0xFF);
}

// Read used capacity from EEPROM
int readEEPROM(int address)
{
  return (EEPROM.read(address) << 8) + EEPROM.read(address + 1);
}
