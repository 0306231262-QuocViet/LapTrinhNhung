#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int Gled = 8;
int Yled = 9;
int Rled = 10;
int btn = 6;
int btnS = LOW;
int lm35 = A0;
int state = 0;
int stateT = 1;
float tempD = 0;
void setup() {

  lcd.begin(16, 2);
  pinMode(Gled, OUTPUT);
  pinMode(Yled, OUTPUT);
  pinMode(Rled, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {
  float temp = (5.0 * analogRead(lm35) * 100.0 / 1024.0);
  float tempF = (temp * 1.8) + 32;
  //LCD
  lcd.setCursor(0, 0);
  lcd.print("TEMP: ");
  lcd.setCursor(6, 0);
  lcd.print(stateT == 1 ? temp : tempF);

  if (btnS == LOW && digitalRead(btn) == HIGH) {
    btnS = digitalRead(btn);
    lcd.clear();
    stateT++;
  }
  btnS = digitalRead(btn);

  switch (stateT) {
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
        stateT = 1;
      }
  }


  state = temp < 17 ? 0 : (temp > 30 ? 2 : 1);

  switch (state) {
    case 0:
      {
        digitalWrite(Gled, HIGH);
        digitalWrite(Yled, LOW);
        digitalWrite(Rled, LOW);
      }
      break;
    case 1:
      {
        digitalWrite(Gled, LOW);
        digitalWrite(Yled, HIGH);
        digitalWrite(Rled, LOW);
      }
      break;
    case 2:
      {
        digitalWrite(Gled, LOW);
        digitalWrite(Yled, LOW);
        digitalWrite(Rled, HIGH);
      }
      break;
  }
}
