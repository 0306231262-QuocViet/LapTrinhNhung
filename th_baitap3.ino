int led = 11;        
int btnGiam = 2;    
int btnTang = 3;
int delayStep = 50;
int btnGiamS = LOW;
int btnTangS = LOW;
int ledState = LOW;
int step = 2000;
unsigned long previousMillis = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  
  // Cài đặt các chân nút nhấn là đầu vào (INPUT)
  pinMode(btnGiam, INPUT);
  pinMode(btnTang, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= step) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(led, ledState);
  }
  if (digitalRead(btnTang) == HIGH && btnTangS==LOW) {
    step -= 50; 
    if (step < 50) {
      step = 50; 
    
    delay(50);
  }
  btnTangS = digitalRead(btnTang);
  if (digitalRead(btnGiam) == HIGH && btnGiamS==LOW) {
    step += 50; 
    if (step > 2000) {
      step = 2000; 
    
    delay(50);
  }
  btnGiamS = digitalRead(btnGiam);
}
