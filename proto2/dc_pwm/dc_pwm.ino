// Motor 1 - BLACK
int speedPinA = 9; // pwm pin to control motor speed
int dir1PinA = 2;
int dir2PinA = 3;

// Motor 2 - WHITE
int speedPinB = 10; // pwm pin to control motor speed
int dir1PinB = 5;
int dir2PinB = 4;

// direction -> 1: forward, 0: backwards
void set_speed_left_wheel(int speedRatio, int dir) {
  analogWrite(speedPinB, speedRatio);
  digitalWrite(dir1PinB, dir == 1 ? HIGH : LOW);
  digitalWrite(dir2PinB, dir == 1 ? LOW  : HIGH);
}

void set_speed_right_wheel(int speedRatio, int dir) {
  analogWrite(speedPinA, speedRatio);
  digitalWrite(dir1PinA, dir == 1 ? HIGH : LOW);
  digitalWrite(dir2PinA, dir == 1 ? LOW  : HIGH);
}

// maneuvers
void mv_forward() {
  // calibration required due to different rpms of wheels
  set_speed_right_wheel(75, 1);
  set_speed_left_wheel(255, 1);
}

void mv_turn_around() {
  set_speed_right_wheel(75, 1);
  set_speed_left_wheel(255, 0);
}


void setup() {
  Serial.begin(9600);

  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);  
}

void loop() {
  mv_forward();

  delay(2000);

  mv_turn_around();

  delay(1000);

  mv_forward();
}
