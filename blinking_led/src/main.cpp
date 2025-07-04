#include <Arduino.h>

const int greenLed = 34;
const int redLed = 35;
const int pb = 38;
bool pbRead = LOW;
bool pbLastread = HIGH;
bool greenState = LOW;

unsigned long blinkInt = 2000;
unsigned long prevTime = 0;
unsigned long currentTime;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(pb, INPUT_PULLUP);
}

void toggleGreen(){
  if(pbRead == LOW && pbLastread == HIGH){
    greenState = !greenState;
    digitalWrite(greenLed, greenState);
  }
   pbLastread = pbRead;
}

void blinkingRed(){
  currentTime = millis();
  if (currentTime - prevTime >= blinkInt){
    prevTime = currentTime;
    digitalWrite (redLed, HIGH);
  }else{
    digitalWrite (redLed, LOW);
  }
}

void loop() {
  pbRead = digitalRead(pb);
  toggleGreen();
  blinkingRed();
}
