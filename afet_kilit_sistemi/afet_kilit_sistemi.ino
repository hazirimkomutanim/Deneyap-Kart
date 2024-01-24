/* Proje afet durumlarında sadece yetkili anahtar/kart
çalıştırılabilen kilit sistemlerini devre dışı bırakır.*/

//RFID
#include <SPI.h>                       
#include <MFRC522.h>          
MFRC522 rfid(D10,D4); 

String fnc_user_ID() {

  rfid.PICC_ReadCardSerial();
  String user_ID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {

    user_ID += (rfid.uid.uidByte[i] < 0x10 ? "0" : " ") + String(rfid.uid.uidByte[i], HEX);

  }

  return user_ID;

}

//MQ-2 
#define MQ_2 A0

int gas = 1200;
int sgnl;

//SERVO
#include <Deneyap_Servo.h>
Servo sservo;

//TILT
#define tilt D8


void setup() {

  Serial.begin(115200);   

  SPI.begin();                       
  rfid.PCD_Init();      

  sservo.attach(D9);
  sservo.write(0);

  pinMode(tilt, INPUT);

}
 

void loop() {

  sgnl = analogRead(MQ_2);
  Serial.print("Gas ->");
  Serial.println(sgnl);
  
  int tiltdegree = digitalRead(tilt);
  Serial.println(tiltdegree);
  delay(250);

  if (sgnl > gas || tiltdegree == 1){ 

    
    sservo.write(180);
    delay(5000);

  }
  else {

    rfidche();

  }
  
}


void rfidche() {
    
    if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {

      Serial.print("Kart UID: ");
      String strID = fnc_user_ID();
      Serial.println(strID);
      Serial.println();

      if (strID.indexOf("e3 e3 eb fc") >= 0) { 
        sservo.write(180);

      }

    delay(5000);

    } 
  
    else {

      sservo.write(0);

    }

  }
  
