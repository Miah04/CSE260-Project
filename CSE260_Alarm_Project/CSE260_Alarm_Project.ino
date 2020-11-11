int IR = 3, FLAME = 4, EM_1 = 5, EM_2 = 6, EM_3 = 7, MASTER = 10, ALERT = 12;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MASTER, INPUT);
  pinMode(IR, INPUT);  //IR
  pinMode(FLAME, INPUT);
  pinMode(EM_1, INPUT);
  pinMode(EM_2, INPUT);
  pinMode(EM_3, INPUT);
  pinMode(ALERT, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool EMERGENCY = (digitalRead(IR) == HIGH || digitalRead(FLAME) == HIGH || digitalRead(EM_1) == HIGH || digitalRead(EM_2) == HIGH || digitalRead(EM_3) == HIGH);
  if(digitalRead(MASTER) == HIGH && EMERGENCY){
    digitalWrite(ALERT, HIGH);
    delay(250);
    digitalWrite(ALERT, LOW);
    delay(250);
  }else{
      digitalWrite(ALERT, LOW);
  }
}
