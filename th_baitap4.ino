int ledRed = 9;     
int ledYellow = 10;  
int btn = 3;
int lastButtonState = LOW;
int state = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int currentButtonState = digitalRead(btn);
  if (lastButtonState == LOW && currentButtonState == HIGH) {
    state++;
    if (state > 4) {
      state = 1;
    }

    delay(50);
    lastButtonState = currentButtonState;

  switch (state) {
    case 1: { 
      digitalWrite(ledYellow, HIGH);
      digitalWrite(ledRed, HIGH);
      break;
    }
    case 2: {
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, LOW);
      break;
    }
    case 3: { 
      digitalWrite(ledYellow, HIGH);
      digitalWrite(ledRed, LOW);
      break;
    }
    case 4: {
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, HIGH);
      break;
    }
    default: { 
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, LOW);
      break;
    }
  }
  }
}
