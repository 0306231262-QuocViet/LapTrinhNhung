#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int led= 8;
int btn = 2;
int pre_btn = LOW;
bool state=true;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(btn,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int cur_btn=digitalRead(btn);
  if(pre_btn==LOW && cur_btn==HIGH){
    if(state==true){
       lcd.noDisplay();
      digitalWrite(led,HIGH);
      state=false;
    }
    else{
       lcd.display();
      digitalWrite(led,LOW);
      state=true;
    }
  
  }
  pre_btn=cur_btn;
}
