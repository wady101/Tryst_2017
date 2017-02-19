/*               This is the code for running a Car with an Arm.
                        Used in IIT-D: Save The Drowning
                          Made by: Eashan Wadhwa
                         Dated: 19th Feburary 2017
*/
//  Variables:
#include<Servo.h>
Servo cl;
Servo sh;
const int mot1r=4;
const int mot1b=7;  
const int mot2r=12;
const int mot2b=13;
int pcl=0;
int el=0;
int w=0;
char stat;
int lper;
int lpul;
//Initialise
void fwd()
{
  digitalWrite(mot1r,HIGH);digitalWrite(mot1b,LOW);
  digitalWrite(mot2r,HIGH);digitalWrite(mot2b,LOW);
  
}
void bkd()
{
  digitalWrite(mot1r,LOW);digitalWrite(mot1b,HIGH);
  digitalWrite(mot2r,LOW);digitalWrite(mot2b,HIGH);
  
}
void lft()
{
  digitalWrite(mot2r,HIGH);digitalWrite(mot2b,LOW);
digitalWrite(mot1r,LOW);digitalWrite(mot1b,HIGH);
  
}
void rt()
{
  digitalWrite(mot1r,HIGH);digitalWrite(mot1b,LOW);
  digitalWrite(mot2r,LOW);digitalWrite(mot2b,HIGH);
}
void stp()
{
  digitalWrite(mot2r,LOW);digitalWrite(mot2b,LOW);digitalWrite(mot1r,LOW);digitalWrite(mot1b,LOW);
}



void setup() {
//  wri.attach(10);
  cl.attach(6);
  sh.attach(11);
  pinMode(5,OUTPUT);
  pinMode(mot1r,OUTPUT);
  pinMode(mot1b,OUTPUT);
  pinMode(mot2r,OUTPUT);
  pinMode(mot2b,OUTPUT);

  //wa.attach(11);
  // put your setup code here, to run once:
Serial.begin(9600);
//       digitalWrite(11,LOW);
//            delayMicroseconds(lpul);

}

void loop(){
  if(Serial.available()>0){
    stat=(char)Serial.read();
    Serial.print(stat);
  }
  if(stat=='F'){fwd();}
  if(stat=='B'){bkd();}
  if(stat=='L'){rt();}
  if(stat=='R'){lft();}
   if(stat=='S'){stp();}
  if (stat=='K')
          {
          delay(10);
        if(pcl>100){pcl--;}
            pcl++;
       cl.write(pcl);}//CLAW OPEN
  if (stat=='X')
           {delay(10);
           if(pcl<2){pcl++;}
             pcl--;
           cl.write(pcl);}//CLAW CLOSE
  if (stat=='M')
            {delay(10);
           if(el>100){el--;}
           el++;
            sh.write(el);}//elbow increase
  if (stat=='N')
            {delay(10);
           if(el<2){el++;}
           el--;
            sh.write(el);}//elbow decrease
  if (stat=='O')
      {//delay(10);
         //  if(w<1){w++;}w--;
           // wa.write(w);
         lper=0.25*1000;
         lpul=0.01*1000;
       pulse(lper,lpul);}//waist left
  if (stat=='P')
      {//delay(10);
         //  if(w>181){w--;}w++;
            //wa.write(w);
          lper=0.06*1000;
          lpul=0.02*1000;
        pulse(lper,lpul);}//waist right

  if (stat=='T'){
    //Serial.println("Stop");
            cl.write(pcl);
            sh.write(el);
            lper=0;
          digitalWrite(5,LOW);
          delayMicroseconds(lper);
              }
}
void pulse(int lper, int lpul){
  digitalWrite(5,HIGH);
delayMicroseconds(lper);
digitalWrite(5,LOW);
delayMicroseconds(lpul);
}

