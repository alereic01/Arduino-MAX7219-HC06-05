#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 1);

void setup() {
  Serial.begin(9600);
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();
    lc.setChar(0, 0, incomingByte, true);
  }
}







/*#include <SPI.h>
#include <LedControl.h>
#include <SoftwareSerial.h>

int DIN = 11;
int CS = 10;
int  CLK = 9;
SoftwareSerial sw (0, 1); // RX, TX
LedControl lc=LedControl(DIN, CLK, CS,1);



void setup()  {
  Serial.begin(57600);
  sw.begin(9600);
  lc.shutdown(0,false);
  lc.setIntensity(0,0);
  lc.clearDisplay(0);
}

void  loop() {
   char data = sw.read();
   for(int i = 0;i<9;i++){
  if(sw.available())
  {
      lc.setLed(0,i,data,true);
    delay(1000);
       lc.setLed(0,i,data,false);
    }
  }

}*/
/* for(int j=0;j<8;j++){
     for(int i=0;i<8;i++){
       lc.setLed(0,j,i,true);
       delay(100);
       lc.setLed(0,j,i,false);
     }
  }*/