/* Ldr ve servo motor ile google trex oyunu */

#include "deneyap.h"
#include "Deneyap_Servo.h"

#define ldr1 A0
#define ldr2 A1

Servo servo;


void setup() {

  Serial.begin(115200);
  Serial.println("START");

  servo.attach(D9);
  int pos = 0;

  servo.write(pos);

}


void loop() {

  int background = analogRead(A0);
  int thing = analogRead(A1);

  Serial.println(background);
  Serial.println(thing);

  delay(50);

  if(background > ...) {

    if(thing > ...)
      servo.write(pos);
    else
      servo.write(pos + 45);

  }
  else {

    if(thing < ...)
      servo.write(pos);
    else
      servo.write(pos + 45);

  }  

}
