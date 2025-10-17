#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int Cbtn = 7;
int CbtnS = LOW;
int Fbtn = 6;
int FbtnS = LOW;

int lm35 = A0;
int state = 1;
void setup() {

  lcd.begin(16, 2);
  pinMode(Cbtn, INPUT);
  pinMode(Fbtn, INPUT);
}

void loop() {
  float temp = (5.0 * analogRead(lm35) * 100.0 / 1024.0);
  float tempF = (temp * 1.8) + 32;

  lcd.setCursor(0, 0);
  lcd.print("TEMP: ");
  lcd.setCursor(6, 0);
  lcd.print(state == 1 ? temp : tempF);

  if (CbtnS == LOW && digitalRead(Cbtn) == HIGH) {
    CbtnS = digitalRead(Cbtn);
    lcd.clear();
    state = 1;
  }
  CbtnS = digitalRead(Cbtn);
  if (FbtnS == LOW && digitalRead(Fbtn) == HIGH) {
    FbtnS = digitalRead(Fbtn);
    lcd.clear();
    state = 2;
  }
  FbtnS = digitalRead(Fbtn);

  switch (state) {
    case 1:
      {
        lcd.print(char(223));
        lcd.print("C ");
      }
      break;
    case 2:
      {
        lcd.print(char(223));
        lcd.print("F ");
      }
      break;
    default:
      {
        state = "C";
      }
  }
}
