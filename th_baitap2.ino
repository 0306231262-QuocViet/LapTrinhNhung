int d1[] = {1,2,3};
int d2[] = {4,5,6};
int d3[] = {7,8,9};
int d4[] = {10,11,12};
int led[] = {1,2,3,4,5,6,7,8,9,10,11,12};
int interval = 3000;
int state = 1;
unsigned long long preMillis = 0;
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i< sizeof(led); i++){
    pinMode(led[i],OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long long currMillis = millis();
  if (currMillis-preMillis >= interval){
    preMillis = currMillis;
    state++;
  }
  switch (state){
    case 1: {
      interval = 3000;
      digitalWrite(d1[0],LOW);
      digitalWrite(d3[0],LOW);
      digitalWrite(d1[1],LOW);
      digitalWrite(d3[1],LOW);
      digitalWrite(d2[1],LOW);
      digitalWrite(d4[1],LOW);
      digitalWrite(d2[2],LOW);
      digitalWrite(d4[2],LOW);

      digitalWrite(d1[2],HIGH); // d1 xanh
      digitalWrite(d3[2],HIGH); // d3 xanh
      digitalWrite(d2[0],HIGH); // d2 do
      digitalWrite(d4[0],HIGH); // d4 do
    }break;
    case 2: {
      interval = 2000;
      digitalWrite(d1[0],LOW);
      digitalWrite(d3[0],LOW);
      digitalWrite(d1[2],LOW);
      digitalWrite(d3[2],LOW);
      digitalWrite(d2[1],LOW);
      digitalWrite(d4[1],LOW);
      digitalWrite(d2[2],LOW);
      digitalWrite(d4[2],LOW);

      digitalWrite(d1[1],HIGH); //d1 vang
      digitalWrite(d3[1],HIGH); //d3 vang
      digitalWrite(d2[0],HIGH); //d2 do
      digitalWrite(d4[0],HIGH); //d4 do
    }break;
    case 3: {
      interval = 3000;

      digitalWrite(d2[0],LOW);
      digitalWrite(d4[0],LOW);
      digitalWrite(d2[1],LOW);
      digitalWrite(d4[1],LOW);
      digitalWrite(d1[1],LOW);
      digitalWrite(d3[1],LOW);
      digitalWrite(d1[2],LOW);
      digitalWrite(d3[2],LOW);

      digitalWrite(d2[2],HIGH);
      digitalWrite(d4[2],HIGH);
      digitalWrite(d1[0],HIGH);
      digitalWrite(d3[0],HIGH);

    }break;
    case 4: {
      interval = 2000;
      digitalWrite(d2[0],LOW);
      digitalWrite(d4[0],LOW);
      digitalWrite(d2[2],LOW);
      digitalWrite(d4[2],LOW);
      digitalWrite(d1[1],LOW);
      digitalWrite(d3[1],LOW);
      digitalWrite(d1[2],LOW);
      digitalWrite(d3[2],LOW);

      digitalWrite(d2[1],HIGH);
      digitalWrite(d4[1],HIGH);
      digitalWrite(d1[0],HIGH);
      digitalWrite(d3[0],HIGH);
    }break;
    default: {interval = 3000; state = 1;};
  }

}