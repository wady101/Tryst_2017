// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


//#include <Servo.h> 
 
//Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
//int pos = 9950;    // variable to store the servo position 
 
void setup() 
{ 
  pinMode(9,OUTPUT);
} 
int lper=0.25*1000;//2 for clockwise
int lpul=0*1000;
void loop() 
{
digitalWrite(9,HIGH);
delayMicroseconds(lper);
digitalWrite(9,LOW);
delayMicroseconds(lpul);
//delay(2000);

  } 
