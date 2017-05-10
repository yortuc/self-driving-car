#include <Servo.h>

Servo sg90;

void setup() {

  sg90.attach(9);

  

}

void loop() {

  sg90.write(0);

  

}
