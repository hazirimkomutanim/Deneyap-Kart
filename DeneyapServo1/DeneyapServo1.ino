#include "deneyap.h"
#include <Deneyap_Servo.h>

Servo servox, servoy;

#define swpin D0
#define xpin A0
#define ypin A1
#define servoxx D9
#define servoyy D14

int xval, yval;
int posx = 0;
int posy = 0;
int dly = 10;
int dival = 0;
int tetaxmin = 0;
int tetaxmax = 180;
int tetaymin = 0;
int tetaymax = 180;
int stp = 1;


void setup() {

  servox.attach(servoxx);
  servoy.attach(servoyy);

  pinMode(swpin, INPUT_PULLUP);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);

  digitalWrite(swpin, 1);

}


void loop() {

  dival = digitalRead(swpin);
  xval = analogRead(xpin);
  yval = analogRead(ypin);

  if(dival < 1) {

    if(dly == 5)
      dly = 10;
    else{
      if(dly == 10)
        dly = 20;
    }
  delay(500);

  }

  if(xval>1000 && posx > tetaxmin)
    posx -= stp;
  if(xval>3000 && posx < tetaxmin)
    posx += stp;
  if(yval>1000 && posy > tetaymin)
    posy -= stp;
  if(yval>3000 && posy > tetaymin)
    posy += stp;

  servox.write(posx);
  servoy.write(posy);

  delay(dly);

}
