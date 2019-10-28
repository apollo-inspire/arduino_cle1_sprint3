const int  buttonPin = 10;

int buttonState = 0;

int lastButtonState;



void setup() {

  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  lastButtonState = LOW;

}

void loop() {
  
  buttonState = digitalRead(buttonPin);

    
  if(buttonState == HIGH){
     Serial.println("on");
  } else {
    Serial.println("off");
    }

}
