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

int mode = 1;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  tempsensor.begin(0x19);
}

void temp () {
  float c = tempsensor.readTempC();
  if (mode = 1) {
      lcd.setCursor(0,0);
      lcd.print("Current Temp.");
      lcd.setCursor(6,1);
      lcd.print("deg. C");
  }
  lcd.setCursor(0,1);
  lcd.print("      "); // Clear the field
  lcd.setCursor(0,1);
  lcd.print(c);
}


void loop() {
  uint8_t buttons = lcd.readButtons();

  if (buttons) {
    lcd.clear();
    lcd.setCursor(0,0);
    if (buttons & BUTTON_UP) {
      mode = 1;
    }
    if (buttons & BUTTON_DOWN) {
      mode = 2;
    }
    if (buttons & BUTTON_LEFT) {
      mode = 3;
    }
    if (buttons & BUTTON_RIGHT) {
      mode = 4;
    }
    if (buttons & BUTTON_SELECT) {
      mode = 5;
  }
}
}
