#include "Arduino.h"
#ifndef BOT_H_
#define BOT_H_

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

void botForward(float dist, float speed){
 // Full speed forward dist in inches
 servoLeft.writeMicroseconds(1500-(200/(speed/100))); // Left wheel counterclockwise
 servoRight.writeMicroseconds(1500+(200/(speed/100))); // Right wheel clockwise
 delay(dist/6*1000);
}

void botBackward(float dist, float speed){
 // Full speed backward dist in inches
 servoLeft.writeMicroseconds(1500+(200/(speed/100))); // Left wheel counterclockwise
 servoRight.writeMicroseconds(1500-(200/(speed/100))); // Right wheel clockwise
 delay(dist/6*1000);
}

void botStop(){
 // Full speed backward
 servoLeft.writeMicroseconds(1500); // Left wheel counterclockwise
 servoRight.writeMicroseconds(1500); // Right wheel clockwise
}

void botLeftTurn(float dist){
 // Zero point left turn
 servoLeft.writeMicroseconds(1300); // Left wheel counterclockwise
 servoRight.writeMicroseconds(1300); // Right wheel clockwise
 delay(dist);
}

void botRightTurn(float dist){
 // Zero point right turn
 servoLeft.writeMicroseconds(1700); // Left wheel counterclockwise
 servoRight.writeMicroseconds(1700); // Right wheel clockwise
 delay(dist);
}

void botLeftPivot(float dist){
 // Pivot Forward-Left
 servoLeft.writeMicroseconds(1500); // Left wheel stop
 servoRight.writeMicroseconds(1300); // Right wheel clockwise
 delay(dist);
}

void botRightPivotReverse(float dist){
 // Pivot Forward-Right
 servoLeft.writeMicroseconds(1700); // Left wheel CCW
 servoRight.writeMicroseconds(1500); // Right wheel stop
 delay(dist);
}

void botLeftPivotReverse(float dist){
 // Pivot Backward-Left
 servoLeft.writeMicroseconds(1500); // Left wheel stop
 servoRight.writeMicroseconds(1700); // Right wheel CCW
 delay(dist);
}

void botRightPivot(float dist){
 // Pivot Backward-Right
 servoLeft.writeMicroseconds(1300); // Left wheel CW
 servoRight.writeMicroseconds(1500); // Right wheel stop
 delay(dist);
}

void botAccel(float time,float start, float stop){
  for (float speed = 0; speed <= stop - start; speed += 2){
    servoLeft.writeMicroseconds(start-speed);
    servoRight.writeMicroseconds(start+speed);
    delay(time);
  }
}

void botDecel(float time, float start, float stop){
  for (float speed = 100; speed >= start - stop; speed -= 2){
    servoRight.writeMicroseconds(start + speed);
    servoLeft.writeMicroseconds(start - speed);
    delay(time);
  }
}

void botBankLeft(float deg, float time){
  for (float speed = 100; speed >= 0; speed -= 2){
    Serial.println(speed);
    servoRight.writeMicroseconds(1500+(speed*(deg/100)));
    servoLeft.writeMicroseconds(1500-speed);
    delay(time);
  }
}

void botBankRight(float deg, float time){
  for (float speed = 100; speed >= 0; speed -= 2){
    servoRight.writeMicroseconds(1500+speed);
    servoLeft.writeMicroseconds(1500-(speed*(deg/100)));
    delay(time);
  }
}

void botDisableMotors(){
  servoLeft.detach();
  servoRight.detach();
}

void botManeuver(float speedLeft, float speedRight, float msTime){
  servoLeft.writeMicroseconds(1500 - speedLeft);
  servoRight.writeMicroseconds(1500 + speedRight);
  if(msTime ==-1){
    botDisableMotors();
  }
  delay(msTime);
}

#endif