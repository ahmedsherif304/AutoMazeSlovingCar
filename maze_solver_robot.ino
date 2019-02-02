#include<NewPing.h>
#include<Servo.h>
int in1=4;   int in2=8;   int in3=12;   int in4=7;
int enA1=5;    int enA2=6;
int trig=3;    int echo=11;    int maxdist=400;
int led=10;   int ldr=A0;   int ledinput;
int x;    int y;    bool z=true;  bool c=true;      bool b =true;
int reading;   int readingus;    

Servo servo;    int S=9;
NewPing US (trig,echo,maxdist);
void setup() {
 servo.attach(S);    pinMode(in1,OUTPUT);   pinMode(in2,OUTPUT);    pinMode(in3,OUTPUT);    pinMode(in4,OUTPUT);
 pinMode(enA1,INPUT);    pinMode(enA2,INPUT);    pinMode(led,OUTPUT);  pinMode(ldr,INPUT);   digitalWrite(led,LOW);
 digitalWrite(in1,LOW);   digitalWrite(in2,LOW);    digitalWrite(in3,LOW);    digitalWrite(in4,LOW);  
 Serial.begin(115200);     servo.write(90);
}

void loop() {
reading=analogRead(ldr);      reading=constrain(reading,900,1023);
ledinput=map(reading,900,1023,0,255);   analogWrite(led,ledinput);
digitalWrite(in1,HIGH);       digitalWrite(in2,LOW);
digitalWrite(in3,LOW);        digitalWrite(in4,HIGH);
analogWrite(enA1,120);        analogWrite(enA2,120);   
readingus=US.ping_cm();   Serial.println(readingus);  
while (readingus<=20 && readingus!=0)
{
readingus=30;
c=true;       b =true;
digitalWrite(in1,LOW);       digitalWrite(in2,LOW);
digitalWrite(in3,LOW);       digitalWrite(in4,LOW);
servo.write(0);     delay(630);           x=US.ping_cm();
servo.write(180);   delay(630);           y=US.ping_cm();
servo.write(90);
if(x>y && c==true)
{
digitalWrite(in1,HIGH);       digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);       digitalWrite(in4,LOW);
delay(500);
digitalWrite(in1,LOW);       digitalWrite(in2,LOW);
digitalWrite(in3,LOW);       digitalWrite(in4,LOW);
delay(500);
c=false;
  }
  else if(y>x && b==true)
  {
digitalWrite(in1,LOW);       digitalWrite(in2,HIGH);
digitalWrite(in3,LOW);       digitalWrite(in4,HIGH);
delay(500);
digitalWrite(in1,LOW);       digitalWrite(in2,LOW);
digitalWrite(in3,LOW);       digitalWrite(in4,LOW);
delay(500);
b=false;    
 }
}
}
