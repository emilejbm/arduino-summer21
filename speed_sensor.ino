#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_MMA8452Q.h>

// initialize pin variables
MMA8452Q accel;
int led1 = 8;
int trig1 = 10;
int trig2 = 6;
int echo1 = 11;
int echo2 = 7;

// initialize distance between ultrasonics in mm
float gap = 150.0; 

// initialize getDistance variables
int duration1 = 0;
int distance1 = 0;
int duration2 = 0;
int distance2 = 999; // cannot be 0 due to error in sensor

// initialize time counting variables
float time1;
float time2;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  accel.init();

  Serial.begin(9600);
}

void getDistance1() {
  // send ultrasonic wave using trig pin
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  // read wave using echo pin
  duration1 = pulseIn(echo1, HIGH);

  // calculate distance in cm
  distance1 = duration1 * 0.034 / 2;
}

void getDistance2() {
  // send ultrasonic wave using trig pin
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  // read wave using echo pin
  duration2 = pulseIn(echo2, HIGH);

  // calculate distance in cm
  distance2 = duration2 * 0.034 / 2;
}

void loop() {
  // read distance from first ultrasonic
  getDistance1(); 

  // number of microseconds since program began running
  time1 = micros();
  
  // if object is within 10 cm of first ultrasonic
  // 0 is needed to account for error in sensor
  if ((distance1 > 0) and (distance1 < 10)) {

    // turn on LED to indicate program is running
    //digitalWrite(led1, HIGH);

    // reset distance2 for the following while loop
    distance2 = 999;

    // while object is NOT in front of second ultrasonic
    // 0 is needed to account for error in sensor
    while ((distance2 == 0) or (distance2 > 10)) {

      // read distance from second ultrasonic
      getDistance2();

      // number of microseconds since program began running
      time2 = micros();
    }
  }
    
    // calculate time it took for object to pass between sensors
    float timePassed = (time2 - time1) / 1000.0;

    // calculate the speed of the object
    float speedValue = gap / timePassed;

    //print acceleration if speed is above 1 m/s
    if(speedValue > 1){
      accel.read();
      float xAcceleration = accel.x;
      Serial.print("Acceleration on the x-axis is: ");
      Serial.println(xAcceleration);    
      digitalWrite(led1, HIGH);
    }
    
    // output data to serial monitor
    Serial.print("time (ms): ");
    Serial.println(timePassed);
    Serial.print("speed (m/s): ");
    Serial.println(speedValue);
    Serial.println(" ");
    //digitalWrite(led1, LOW); // turn off LED
    delay(2000); // wait 2 seconds
  
}
