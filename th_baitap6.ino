#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int power_btn = 8;
int left_btn= 9;
int right_btn = 10;

int pre_power = HIGH;
int pre_left = HIGH;
int PRE_RIGHT = HIGH;
bool screenOn = true;
int pos = 0;


void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(pos, 0);
  lcd.print("HELLO!");

  pinMode(power_btn, INPUT);
  pinMode(left_btn, INPUT);
  pinMode(right_btn, INPUT);
}

void loop() {
  int power_tt = digitalRead(power_btn);
  int left_tt = digitalRead(left_btn);
  int right_tt = digitalRead(right_btn);

  if (power_tt == LOW && pre_power == HIGH) {
    screenOn = !screenOn;
    if (screenOn) lcd.display();
    else lcd.noDisplay();
    
  }

  if (left_tt == LOW && pre_left == HIGH) {
    pos -= 2;
    if (pos < 0) pos = 0;
    lcd.clear();
    lcd.setCursor(pos, 0);
    lcd.print("HELLO!");
    
  }

  if (right_tt == LOW && pre_right == HIGH) {
    pos += 2;
    if (pos > 11) pos = 11;
    lcd.clear();
    lcd.setCursor(pos, 0);
    lcd.print("HELLO!");
    
  }

  pre_power = power_tt;
  pre_left = left_tt;
  pre_right = right_tt;
}
