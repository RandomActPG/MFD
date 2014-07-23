// include the library code:
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_MCP9808.h>

// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();


void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  tempsensor.begin(0x19);
}

void temp () {
  float c = tempsensor.readTempC();
  lcd.setCursor(0,0);
  lcd.print("Current Temp.");
  lcd.setCursor(0,1);
  lcd.print(c);
  lcd.setCursor(6,1);
  lcd.print("deg. C");
}

void loop() {
  temp();
}

//this is the button-driven code, not used yet//
/*void loop() {
  uint8_t buttons = lcd.readButtons();

  if (buttons) {
    lcd.clear();
    lcd.setCursor(0,0);
    if (buttons & BUTTON_UP) {
      lcd.print("UP ");
    }
    if (buttons & BUTTON_DOWN) {
      lcd.print("DOWN ");
    }
    if (buttons & BUTTON_LEFT) {
      lcd.print("LEFT ");
    }
    if (buttons & BUTTON_RIGHT) {
      lcd.print("RIGHT ");
    }
    if (buttons & BUTTON_SELECT) {
      temp();}
    }
 }
*/
 
