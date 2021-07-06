#include <Arduino.h>

int led1 = 8;
int trig1 = 12;
int echo1 = 13;
int unit = 90;

float duration = 0;
float distance = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
 
}

void getDistance(){
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  duration = pulseIn(echo1, HIGH);

  distance = duration * 0.034 / 2;
}

void loop() {
  // put your main code here, to run repeatedly:
  getDistance();
  while(distance < 30){
    if((distance >= 10) and (distance <= 20)){
      digitalWrite(led1, HIGH);
    }
    if(distance < 10){
      callSOS();
    }
    getDistance();
  }

   digitalWrite(led1, LOW); 
   Serial.print("Distance: ");
   Serial.println(distance);
}

void dot(){
  digitalWrite(led1, HIGH);
  delay(unit);
  digitalWrite(led1, LOW);
}

void dash(){
  digitalWrite(led1, HIGH);
  delay(unit * 3);
  digitalWrite(led1, LOW);
}

void callSOS(){
  //S
  dot();
  delay(unit);
  dot();
  delay(unit);
  dot();

  delay(unit * 3);
  
  //O
  dash();
  delay(unit);
  dash();
  delay(unit);
  dash();

  delay(unit * 3);
  
  //S
  dot();
  delay(unit);
  dot();
  delay(unit);
  dot();
  
}
