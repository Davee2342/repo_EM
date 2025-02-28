#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd.begin(16,2);
  lcd.backlight();
}

void loop() {
  for (int i = 1; i <= 10; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" ");
    lcd.print(i);
    delay(1000); // Wait for 1 second
  }

  for (int i = 100; i >= 1; i--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" ");
    lcd.print(i);
    delay(1000); // Wait for 1 second
  }
}
