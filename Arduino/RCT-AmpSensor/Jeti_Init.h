//
// Stuff done in initialization of sketch
//

// Jetibox start screen
#define ABOUT_1 F(" RCT Jeti Tools")
#define ABOUT_2 F(" AmpSensor 1.4")

// Max screens in Jetibox
#define MAX_SCREEN 10

// Sensor type selection
enum sensorType {
  None,
  ACS712_05A,
  ACS712_20A,
  ACS712_30A,
  ACS758_50B,
  ACS758_100B,
  ACS758_150B,
  ACS758_200B,
  ACS758_50U,
  ACS758_100U,
  ACS758_150U,
  ACS758_200U
};

// Offset for sensors
const int ACSoffsetArray[] =  {
  2500,   // None
  2500,   // ACS712-05
  2500,   // ACS712-20
  2500,   // ACS712-30
  2500,   // ACS758-50B
  2500,   // ACS758-100B
  2500,   // ACS758-150B
  2500,   // ACS758-200B
  600,    // ACS758-50U
  600,    // ACS758-100U
  600,    // ACS758-150U
  600     // ACS758-200U
};

// Sensors mV per Amp ratio
const float mVperAmpArray[] =  {
  100.0,    // None
  185.0,    // ACS712-05
  100.0,    // ACS712-20
  66.0,     // ACS712-30
  40.0,     // ACS758-50B
  20.0,     // ACS758-100B
  13.3,     // ACS758-150B
  10.0,     // ACS758-200B
  60.0,     // ACS758-50U
  40.0,     // ACS758-100U
  26.7,     // ACS758-150U
  20.0      // ACS758-200U
};

// Voltage Divider selection
enum dividerType {
  Max_14S_60V,
  Max_6S_30V,
  Max_3S_15V,
  Rx_10V
};

// Voltage Divider R1
const int R1[] = {
  11000,
  10000,
  2000,
  2000
};

// Voltage Divider R2
const int R2[] = {
  1000,
  2000,
  1000,
  2000
};

// ID number for sensor (Needs to be unique for all sensors in model 0xA400 – 0xA41F)
const unsigned char Jeti_SensorID4 = 0x09;

//
// Sensor variables & other init-stuff needed
//

// Input pins
const int analogInCur = A3;
const int analogInVolt = A2;

// Jeti values
float uCurrent = 0;
float uCapacity = 0; // was int
float uVoltage = 0;
long uPower = 0;
long jetiCurrent = 0;
long jetiVoltage = 0;
long jetiCapacity = 0;

// Voltage divider - Defaults to 14S / 60V
int dividerR1;
int dividerR2;
float divider;

// Calibration & calculation values
float mVperAmp = 0;
int ACSoffset = 0;
int curCalVal = 0;
int tempcurCalVal = 100;
int voltCalVal = 0;
int tempvoltCalVal = 100;
static float tmpCap = 0;
unsigned long prevMillis = 0; // Previous time in ms
unsigned long curMillis = 0;  // Current time in ms

// Defaults
int sensorType = 0;
int voltageRange = 0;

// Reset function
int pinReset = 5;
int resetFunction = 0;
int resetState = 0;
int currentActive = 0;
int currentStored = 0;
long resetTime = 0;
long curTime = 0;
