#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);

const float referenceVolts = 5;
const float R1 = 5000;
const float R2 = 1000;
const float resistorFactor = 1023.0 * (R2 / (R1 + R2));
const int batteryPin = A0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("    VoltmetrINO     ");
  lcd.setCursor(0, 1);
  lcd.print("  Pagina Facebook:  ");
  lcd.setCursor(0, 2);
  lcd.print("Progetti & Tutorial");
  lcd.setCursor(0, 3);
  lcd.print("      Ardunio       ");
  delay(4000);
  lcd.clear();
}

void loop() {
  int val = analogRead(batteryPin);
  float volts = (val / resistorFactor) * referenceVolts;
  lcd.setCursor(0, 1);
  lcd.print(" Tensione  misurata  ");
  lcd.setCursor(8, 2);
  lcd.print(volts);
  lcd.setCursor(13, 2);
  lcd.print("V");
  delay(500);
}

