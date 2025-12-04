#include <Servo.h>

Servo servo;
int angle = 0;

void setup() {
  servo.attach(11);
  servo.write(angle);
}

void loop() {
  for (angle = 0; angle <= 200; angle += 1) {
    servo.write(angle);
    delay(15);
  }
  for (angle = 200; angle >= 0; angle -= 1) {
    servo.write(angle);
    delay(15);
  }
}
