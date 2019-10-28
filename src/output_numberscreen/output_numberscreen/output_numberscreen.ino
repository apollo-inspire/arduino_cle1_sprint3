#include "SevSeg.h"
SevSeg sevseg;

const int  buttonPin = 10;    // the pin that the pushbutton is attached to
int buttonState = 0;          // current state of the button
int lastButtonState = LOW;    // previous state of the button
int buttonPushCounter = 0;    // counter for the number of button presses
long counter = 0;
long max_long_val = 2147483647L;

void setup() {
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {6, 5, 2 , 3, 4 , 7, 8, 9};
  bool resistorsOnSegments = true;

  byte hardwareConfig = COMMON_CATHODE;
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);

  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  lastButtonState = LOW;
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    buttonState = LOW;
  }

  else
    buttonState = HIGH;

  if (buttonState == HIGH) {
    Serial.println("on");
    lastButtonState = HIGH;
    buttonPushCounter++;
    if (counter < max_long_val)
      counter++;
    buttonPushCounter %= 9;
    sevseg.setNumber(buttonPushCounter, 1);
    sevseg.refreshDisplay();
    delay(100 - (counter % 99));
  }

  else {
    Serial.println("off");
    if (lastButtonState == HIGH) {
      Serial.println("in");
      buttonPushCounter++;
      buttonPushCounter %= 7;
      if (buttonPushCounter == 0)
        buttonPushCounter = 1;
      counter--;
      sevseg.setNumber(buttonPushCounter, 1);
      sevseg.refreshDisplay();
      delay(100 - (counter % 99));
      if (counter == 0) {
        lastButtonState = LOW;
        sevseg.setNumber(buttonPushCounter, 0);
        sevseg.refreshDisplay();
      }
    }
  }
}
