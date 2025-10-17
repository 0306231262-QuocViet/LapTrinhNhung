#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int x = 0;
int y = 0;

byte chu_AA[8] = { 
  B00100,
  B01010,
  B01110,
  B10001,
  B11111,
  B10001,
  B10001,
  B10001
};

byte chu_AW[8] = { 
  B01010,
  B00100,
  B01110,
  B10001,
  B11111,
  B10001,
  B10001,
  B10001
};

byte chu_DD[8] = { 
  B01111,
  B01001,
  B11111,
  B01001,
  B01001,
  B01001,
  B01111,
  B00000
};

byte chu_EE[8] = { 
  B00100,
  B01010,
  B11110,
  B10000,
  B11110,
  B10000,
  B11110,
  B00000
};

byte chu_OO[8] = { 
  B00100,
  B01010,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

byte chu_OW[8] = { 
  B00100,
  B01000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

byte chu_UW[8] = { 
  B00010,
  B00100,
  B10001,
  B10001,
  B10001,
  B10011,
  B01101,
  B00000
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, chu_AA);
  lcd.createChar(1, chu_AW);
  lcd.createChar(2, chu_DD);
  lcd.createChar(3, chu_EE);
  lcd.createChar(4, chu_OO);
  lcd.createChar(5, chu_OW);
  lcd.createChar(6, chu_UW);
  lcd.clear();
}

void loop() {

  
   
  for(int i =0 ; i<7 ;i++){
     lcd.setCursor(x, y);
     lcd.write(byte(i));
     x++;
      if(x >= 15){
        y++;
        }
      if(y > 1){
        x=0; 
        y=0;
        }
    }
  
  delay(200);
}
