const int DST_TRIGGER = 2;
const int DST_ECHO = 3;

int MOTOR_OUT_3 = 5;
int MOTOR_OUT_4 = 4;

void setup() {
  pinMode(DST_TRIGGER, OUTPUT);
  pinMode(DST_ECHO, INPUT);
 
  pinMode(MOTOR_OUT_3, OUTPUT);
  pinMode(MOTOR_OUT_4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int mesafe = mesafe_olc();

  if(mesafe > 0 && mesafe < 10){
    geri();
  }
  else{
    ileri();
  }
}

int mesafe_olc() {
  digitalWrite(DST_TRIGGER, HIGH);
  delayMicroseconds(500);
  digitalWrite(DST_TRIGGER, LOW);
 
  int sure = pulseIn(DST_ECHO, HIGH);
  int mesafe_cm = (sure/2) / 29.1;

  // log
  Serial.print("Mesafe: ");
  Serial.print(mesafe_cm);
  Serial.print(" cm \n");

  return mesafe_cm;
}

void ileri() {
  digitalWrite(MOTOR_OUT_3, HIGH);
  digitalWrite(MOTOR_OUT_4, LOW);
}

void geri() {
  digitalWrite(MOTOR_OUT_3, LOW);
  digitalWrite(MOTOR_OUT_4, HIGH);
}
 
