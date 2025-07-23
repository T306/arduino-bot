// 6in/s robot speed

#include <Servo.h>
#include "bot.h"
#include "notif.h"

bool wLeft = digitalRead(5); //Left Whisker
bool wRight = digitalRead(7); //Right Whisker

void setup(){
  // nokia(4);
  Serial.begin(115200);
  servoLeft.attach(12); // Attach left signal to pin 13
  servoRight.attach(13); // Attach right signal to pin 12
  pinMode(5, INPUT); // Left Whisker
  pinMode(7, INPUT); // Right Whisker
  pinMode(8, OUTPUT); // Left LED
  pinMode(2, OUTPUT); // Right LED
  pinMode(10, INPUT); pinMode(9, OUTPUT); //Left IR reciever & LED
  pinMode(3, INPUT); pinMode(2, OUTPUT); //Right IR reciever & LED
}

void loop(){

  int irLeft = irDetect(9, 10, 38000); // Check for object
  int irRight = irDetect(2, 3, 38000); // Check for object

  botForward(3*12, 100);
  botRightTurn(12);
  botForward(2*12, 100);
  botLeftTurn(12);
  botForward(43*12, 100);

  // if ((irLeft == 0) && (irRight == 0)){
  //   botBackward(0.25, 100);
  // } else if (irLeft == 0){
  //   botRightTurn(3);
  // } else if (irRight == 0){
  //   botLeftTurn(3);
  // } else {
  //   botForward(0.25, 100);
  // }

  // wLeft = digitalRead(5);
  // wRight = digitalRead(7);
  // if ((wLeft == 0) && (wRight == 0)){
  //   digitalWrite(8, HIGH);
  //   digitalWrite(2, HIGH);
  //   botBackward(12, 100);
  //   botLeftTurn(2000);
  // } else if (wLeft == 0){
  //   digitalWrite(8, HIGH);
  //   botBackward(6, 100);
  //   botRightTurn(1000);
  // } else if (wRight == 0){
  //   digitalWrite(2, HIGH);
  //   botBackward(6, 100);
  //   botLeftTurn(1000);
  // } else if (volts(A3) < 0.05){
  //   botBackward(12, 100);
  // } else {}
  //   digitalWrite(8, LOW);
  //   digitalWrite(2, LOW);
  //   botForward(0.25, 100);
}

float volts(int adPin){
  return float(analogRead(adPin))*5.0/1024.0;
}

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
 tone(irLedPin, frequency, 8); // IRLED 38 kHz at least 1 ms
 delay(1); // Wait 1 ms
 int ir = digitalRead(irReceiverPin); // IR receiver -> ir variable
 delay(1); // Down time before recheck
 return ir; // Return 1 no detect, 0 detect
} 
