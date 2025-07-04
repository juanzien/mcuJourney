#include <Arduino.h>
#include <ESP32Servo.h>

ESP32PWM servo;
const int led = 35;
const int pot = A3;
int hasilPot;
int sudut;

void setup() {
  Serial.begin(115200);
  pinMode(pot, INPUT);
  pinMode(led, OUTPUT);
  servo.attachPin(13, 50, 10);
}

void loop() {
  hasilPot = analogRead(pot);
  hasilPot = map(hasilPot, 0, 1203, 0, 255);
  sudut = map(hasilPot, 0, 255, 0, 180);
  analogWrite(led, hasilPot);
  servo.write(sudut);
}

