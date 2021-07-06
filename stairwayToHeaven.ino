#include <Arduino.h>

int buzzerPin = 13;
int red = 10;
int yellow = 11;
int blue = 12;
int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;
int DP = 9;

int A4note = 440;
float B4 = 493.88;
float C4 = 261.63;
float D4 = 293.66;
float E4 = 329.63;
float F4 = 349.23;
int G4 = 392;
float F4sharp = 369.99;

float C5 = 523.25;

int A3note = 220;
float B3 = 246.94;
int G3 = 196;

//notes in 82 WPM
int snote = 732;
int enote = 366;
int qnote = 732;
int hnote = 1463;
int wnote = 2927;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //number countdown from 5
  num_five();
  delay(1000);
  clear_segment();
  num_four();
  delay(1000);
  clear_segment();
  num_three();
  delay(1000);
  clear_segment();
  num_two();
  delay(1000);
  clear_segment();
  num_one();
  delay(1000);
  clear_segment();
  num_zero();
  delay(1000);
  clear_segment();

  //play stairway to heaven intro
  sth_intro();

  exit(0);
 
}

void clear_segment(){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void num_five(){
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
}

void num_four(){
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void num_three(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(D, HIGH);
}

void num_two(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
}

void num_one(){
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void num_zero(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
}

void sth_intro(){
  tone(buzzerPin, A3note, snote);
  digitalWrite(red, HIGH);
  delay(snote);
  digitalWrite(red, LOW);
  tone(buzzerPin, C4, snote);
  digitalWrite(yellow, HIGH);
  delay(snote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, E4, snote);
  digitalWrite(blue, HIGH);
  delay(snote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, A4note, snote);
  digitalWrite(red, HIGH);
  delay(snote);
  digitalWrite(red, LOW);
  tone(buzzerPin, B4, snote);
  digitalWrite(yellow, HIGH);
  delay(snote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, E4, snote);
  digitalWrite(blue, HIGH);
  delay(snote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, C4, snote);
  digitalWrite(yellow, HIGH);
  delay(snote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, B4, snote);
  digitalWrite(yellow, HIGH);
  delay(snote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, C5, snote);
  digitalWrite(blue, HIGH);
  delay(snote);
  digitalWrite(blue, LOW);
  
  tone(buzzerPin, E4, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, C4, qnote);
  digitalWrite(blue, HIGH);
  delay(snote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, C5, qnote);
  digitalWrite(yellow, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, F4sharp, qnote);
  digitalWrite(red, HIGH);
  delay(qnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, D4, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, A3note, qnote);
  digitalWrite(red, HIGH);
  delay(qnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, F4sharp, qnote);
  digitalWrite(red, HIGH);
  delay(qnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, E4, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, C4, qnote);
  digitalWrite(yellow, HIGH);
  delay(qnote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, A3note, wnote);
  digitalWrite(blue, HIGH);
  delay(wnote);
  digitalWrite(blue, LOW);

  delay(500);
  
  tone(buzzerPin, G3, qnote);
  digitalWrite(red, HIGH);
  delay(qnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, A3note, qnote);
  digitalWrite(yellow, HIGH);
  delay(qnote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, A3note, wnote);
  digitalWrite(yellow, HIGH);
  delay(wnote);
  digitalWrite(yellow, LOW);

  delay(1000);
  
  tone(buzzerPin, A3note, qnote);
  digitalWrite(yellow, HIGH);
  delay(qnote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, B3, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, C4, hnote);
  digitalWrite(red, HIGH);
  delay(hnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, B3, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, A3note, qnote);
  digitalWrite(yellow, HIGH);
  delay(qnote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, B3, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);

  delay(500);
  
  tone(buzzerPin, A3note, qnote);
  digitalWrite(yellow, HIGH);
  delay(qnote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, C4, hnote);
  digitalWrite(red, HIGH);
  delay(hnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, D4, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, C4, qnote);
  digitalWrite(red, HIGH);
  delay(qnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, A3note, hnote);
  digitalWrite(yellow, HIGH);
  delay(hnote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, C4, qnote);
  digitalWrite(red, HIGH);
  delay(qnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, D4, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, E4, hnote);
  digitalWrite(yellow, HIGH);
  delay(hnote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, D4, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, C4, qnote);
  digitalWrite(red, HIGH);
  delay(qnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, B3, hnote);
  digitalWrite(blue, HIGH);
  delay(hnote);
  digitalWrite(blue, LOW);

  delay(250);
  
  tone(buzzerPin, G3, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, G3, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, A3note, hnote);
  digitalWrite(yellow, HIGH);
  delay(hnote);
  digitalWrite(yellow, LOW);

  delay(500);
  
  tone(buzzerPin, A3note, qnote);
  digitalWrite(yellow, HIGH);
  delay(qnote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, B3, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, C4, hnote);
  digitalWrite(red, HIGH);
  delay(hnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, B3, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, A3note, qnote);
  digitalWrite(yellow, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, B3, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);

  delay(500);

  tone(buzzerPin, A3note, qnote);
  digitalWrite(yellow, HIGH);
  delay(qnote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, C4, hnote);
  digitalWrite(red, HIGH);
  delay(hnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, D4, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, C4, qnote);
  digitalWrite(red, HIGH);
  delay(qnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, A3note, hnote);
  digitalWrite(yellow, HIGH);
  delay(hnote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, C4, qnote);
  digitalWrite(red, HIGH);
  delay(qnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, D4, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, E4, hnote);
  digitalWrite(yellow, HIGH);
  delay(hnote);
  digitalWrite(yellow, LOW);
  tone(buzzerPin, D4, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, C4, qnote);
  digitalWrite(red, HIGH);
  delay(qnote);
  digitalWrite(red, LOW);
  tone(buzzerPin, B3, hnote);
  digitalWrite(blue, HIGH);
  delay(hnote);
  digitalWrite(blue, LOW);

  delay(250);

  tone(buzzerPin, G3, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, G3, qnote);
  digitalWrite(blue, HIGH);
  delay(qnote);
  digitalWrite(blue, LOW);
  tone(buzzerPin, A3note, hnote);
  digitalWrite(yellow, HIGH);
  delay(hnote);
  digitalWrite(yellow, LOW);
}
