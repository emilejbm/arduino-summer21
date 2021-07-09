#include <Arduino.h>
#include <Servo.h>
#include <Stepper.h>

int stepsPerRevolution = 800;
int servoPin = 3;
int photocellPin = 0; //a0
int reading;
int redLED = 9;
int brightness;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
Servo Servo1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(servoPin, OUTPUT);
  Servo1.attach(servoPin);

  //stepper code
  //myStepper.setSpeed(20);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = analogRead(photocellPin);

  Serial.print("Analog reading: ");
  Serial.println(reading);

  if(reading < 10){
    Serial.println("Dark");

    digitalWrite(redLED, HIGH);
    //servo motor will rotate
    Servo1.write(0);
    delay(1000);

    Servo1.write(90);
    delay(1000);

    Servo1.write(180);
    delay(1000);
  }
  else if (reading < 200){
    Serial.println("Dim");
    
    digitalWrite(redLED, HIGH);
    //servo motor will rotate
    Servo1.write(0);
    delay(1000);

    Servo1.write(90);
    delay(1000);

    Servo1.write(180);
    delay(1000);
  }
  else if(reading < 500) {
    Serial.println("Light");
    digitalWrite(redLED, LOW);
  } 
  else if (reading < 800) {
    Serial.println("Bright");
    digitalWrite(redLED, LOW);
  } 
  else {
    Serial.println("Very bright");
    digitalWrite(redLED, LOW);
  }

  //delay(1000);
  
  /*stepper code
  
  myStepper.step(stepsPerRevolution);
  delay(500);

  myStepper.step(-stepsPerRevolution);
  delay(500);
  */

}
