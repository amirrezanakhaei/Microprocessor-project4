
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte armsDown[8] = {
  B00100, B01010, B00100, B00100, B01110, B10101, B00100, B01010
};

byte armsUp[8] = {
  B00100, B01010, B00100, B10101, B01110, B00100, B00100, B01010
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, armsDown);
  lcd.createChar(1, armsUp);
  lcd.print("Diagonal Dance!");
  delay(1500);
}

void loop() {
  for (int col = 0; col < 16; col++) {
    lcd.clear();
    if (col % 2 == 0) {
      lcd.setCursor(col, 0);
      lcd.write(byte(1));
    } else {
      lcd.setCursor(col, 1);
      lcd.write(byte(0));
    }
    delay(300);
  }

  for (int col = 15; col >= 0; col--) {
    lcd.clear();
    if (col % 2 != 0) {
      lcd.setCursor(col, 0);
      lcd.write(byte(1));
    } else {
      lcd.setCursor(col, 1);
      lcd.write(byte(0));
    }
    delay(300);
  }
}
