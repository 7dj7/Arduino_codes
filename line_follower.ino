/* ADAFRUIT Motor shield has been used for controlling the DC motors

CONNECTIONS/ PIN LAYOUT---

Left Motor - M4
Right Motor - M3
Right IR Sensor - A5
Left IR Sensor - A4

***** IR sensors need to be properly calibrated *****

*/

#include <AFMotor.h>

AF_DCMotor left(4);
AF_DCMotor right(3);

void setup() {
 pinMode(A5, INPUT); //rightir
 pinMode(A4, INPUT); //leftir
 Serial.begin(9600);
}

void loop() {
 left.setSpeed(255);
 right.setSpeed(255);
 if((analogRead(A5)<945)&&(analogRead(A4)<945))
  {
    left.run(FORWARD);
    right.run(FORWARD);
  }
  if((analogRead(A4)>945)&&(analogRead(A5)<945))
  {
    left.run(RELEASE);
    right.run(FORWARD);
    delay(100);
  }
 if((analogRead(A5)>945)&&(analogRead(A4)<945))
  {
    right.run(RELEASE);
    left.run(FORWARD);
    delay(100);
  }
  if((analogRead(A5)>945)&&(analogRead(A4)>945))
  {
    left.run(RELEASE);
    right.run(RELEASE);
  }
 

}
