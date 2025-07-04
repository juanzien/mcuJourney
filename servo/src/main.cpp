#include <Arduino.h>
#include <ESP32Servo.h>

ESP32PWM servo;

const int freq = 50;
const int leftpb = 36;
const int rightpb = 39;
const int redLed = 25;
const int greenLed = 27;
int sudut;
bool rightpbState;
bool leftpbState;

unsigned long prevTime = 0;
unsigned long blinkInt = 3000;
unsigned long currentTime;

void setup() {
  Serial.begin(115200);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(leftpb, INPUT);
  pinMode(rightpb, INPUT);
  servo.attachPin(13, freq, 10);
}

void rightServo(){
  if (rightpbState == HIGH) {
    sudut ++;
    servo.write(sudut);
    if (currentTime - prevTime >= blinkInt){
      digitalWrite(greenLed, HIGH);
    }
}
}


void leftServo(){
if (leftpbState == HIGH) {
    sudut --;
    servo.write(sudut);
    if (currentTime - prevTime >= blinkInt){
      digitalWrite(redLed, HIGH);
    }
}
}

void loop() {
  currentTime = millis();
  rightpbState = digitalRead(rightpb);
  leftpbState = digitalRead(leftpb);

  rightServo();
  leftServo();
}

