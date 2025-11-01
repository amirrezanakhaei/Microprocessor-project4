#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte Heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};
byte Check[8] = {
  0b00000,
  0b00001,
  0b00011,
  0b10110,
  0b11100,
  0b01000,
  0b00000,
  0b00000
};
byte Lock[8] = {
  0b01110,
  0b10001,
  0b10001,
  0b11111,
  0b11011,
  0b11011,
  0b11111,
  0b00000
};
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);

  lcd.createChar(0, Heart);
  lcd.createChar(3, Check);
  lcd.createChar(7, Lock);
  lcd.clear();
  lcd.print("Custom Character");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 1);
  lcd.write(byte(0));

  lcd.setCursor(6, 1);
  lcd.write(byte(3));

  lcd.setCursor(14, 1);
  lcd.write(byte(7));

}
