//#include <Wire.h>
int latchPin = 3;
int clockPin = 5;
int dataPin = 2;
int enablePin=11;

int a = 0;
 
int leds1 = 0;
int leds2 = 0;
int value = B10000000;
int value2 = B00000001;


void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  


  //Wire.begin();
  //digitalWrite(enablePin, LOW); 
  analogWrite(enablePin, 0); 
  

}

void updateShiftRegister()
{
   
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, MSBFIRST, leds2);
   shiftOut(dataPin, clockPin, MSBFIRST, 255);
   shiftOut(dataPin, clockPin, MSBFIRST, 255);
   shiftOut(dataPin, clockPin, MSBFIRST, 255);
   shiftOut(dataPin, clockPin, MSBFIRST, 255);
   shiftOut(dataPin, clockPin, MSBFIRST, 255);
   shiftOut(dataPin, clockPin, MSBFIRST, 255);
   shiftOut(dataPin, clockPin, MSBFIRST, 255);
   shiftOut(dataPin, clockPin, MSBFIRST, 255);
   
   shiftOut(dataPin, clockPin, MSBFIRST, leds1);
   //delayMicroseconds(100);
   digitalWrite(latchPin, HIGH);
   
   delayMicroseconds(250);

   
   
   
   
   
}              


void loop() {
  value = B10000000;
  value2 = B00000001;
 for (int i = 0; i <= 7; i++) {
 leds1=255-(value>>i);
 leds2=255-(value2<<i);
 
 updateShiftRegister();
 delay(100);
 
 }   
 
   
   



}
