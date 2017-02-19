
/*               This is the code for running a Car with an Arm.
                        Used in IIT-D: Save The Drowning
                          Made by: Eashan Wadhwa
                         Dated: 19th Feburary 2017
*/
//  Variables:
#include<Servo.h>
Servo wri;
Servo cl;
Servo sh;
const int mot1r=46;
const int mot1b=47;  
const int mot2r=30;
const int mot2b=31;
int pcl=0;
int wr=0;
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
  wri.attach(10);
  cl.attach(6);
  sh.attach(8,1000,2000);
  pinMode(2,OUTPUT);
  pinMode(mot1r,OUTPUT);
  pinMode(mot1b,OUTPUT);
  pinMode(mot2r,OUTPUT);
  pinMode(mot2b,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  //wa.attach(11);
  // put your setup code here, to run once:
Serial.begin(9600);
//       digitalWrite(11,LOW);
//            delayMicroseconds(lpul);

}

void loop(){
  analogWrite(3,255);//E1
analogWrite(5,255);//E2
        // digitalWrite(11,LOW);
      //      delayMicroseconds(lpul);
  if(Serial.available()>0){
    stat=(char)Serial.read();
    //Serial.print(stat);
  }
  if(stat=='F'){fwd();}
  if(stat=='B'){bkd();}
  if(stat=='L'){lft();}
  if(stat=='R'){rt();}
  if(stat=='X'){analogWrite(3,255);//RT;    //FWD LEFT
                 analogWrite(5,50);//LT;
                  fwd();}
  if(stat=='Z'){analogWrite(3,50);    //FWD RIGHT
                analogWrite(5,255);
                fwd();}
  if(stat=='S'){analogWrite(3,255);    //BACK LEFT
                 analogWrite(5,120);
                 bkd();}
  if(stat=='Y'){analogWrite(3,120);    //BACK RIGHT
                 analogWrite(5,255);
                 bkd();}
  if(stat=='E'){stp();}
  if (stat=='K')
          {
          delay(10);
        if(pcl>100){pcl--;}
            pcl++;
       cl.write(pcl);}//CLAW OPEN
  if (stat=='V')
           {delay(10);
           if(pcl<2){pcl++;}
             pcl--;
           cl.write(pcl);}//CLAW CLOSE
  if (stat=='M')
           {delay(10);
           if(wr>100){wr--;}
             wr++;
           wri.write(wr);}//wrist increase
  if (stat=='N')
           {delay(10);
           if(wr<2){wr++;}wr--;
           wri.write(wr);}//wrist decrease
  if (stat=='O')
            {delay(100);
          //if(el>180){el--;}
           el++;
            sh.write(el);}//elbow increase
  if (stat=='P')
            {delay(100);
          // if(el<2){el++;}
           el--;
            sh.write(el);}//elbow decrease
  if (stat=='Q')
      {//delay(10);
         //  if(w<1){w++;}w--;
           // wa.write(w);
        lper=0.27*1000;
         lpul=.04*1000;
       pulse(lper,lpul);
     }//waist left
 if (stat=='U')
      {//delay(10);
         //  if(w>181){w--;}w++;
            //wa.write(w);
          lper=.15*1000;
         lpul=.04*1000;
      pulse(lper,lpul);
   }//waist right

  if (stat=='T'){
    //Serial.println("Stop");
            cl.write(pcl);
            wri.write(wr);
            sh.write(el);
            //wa.write(w);
      //      lper=0;
       lper=0;
          digitalWrite(2,LOW);
         delayMicroseconds(lper);
              }
}
void pulse(int lper, int lpul){
  digitalWrite(2,HIGH);
delayMicroseconds(lper);
digitalWrite(2,LOW);
delayMicroseconds(lpul);
}

