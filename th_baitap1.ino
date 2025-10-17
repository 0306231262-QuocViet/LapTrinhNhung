int led[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int soLuongDen = 10;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < soLuongDen; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < soLuongDen; i++) {
    long soNgauNhien = random(1,100);
    if (soNgauNhien % 2 != 0) {
      digitalWrite(led[i], HIGH);
    }else{
      digitalWrite(led[i], LOW);
    }

  }
  delay(1000);
}
