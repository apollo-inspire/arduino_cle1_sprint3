// Libraries
#include <Servo.h> 


// sonar
// defines pins numbers
#define PIN_TRIGSONAR 9
#define PIN_ECHOSONAR 10

// sonar
// defines variables
long durationSonar;
int distanceSonar;

// servo
// Declare the Servo pin 
int servoPin = 3;


// servo
// Create a servo object 
Servo Servo1; 



// servo
// Change servo to
void servoAttack() {
  Serial.println("SERVO ATTACK MODE"); 
  Servo1.write(0);
  delay(100);
  Servo1.write(180);
  delay(100);
  Servo1.write(0);
  delay(100);
  }




void setup() {

  // sonar
  pinMode(PIN_TRIGSONAR, OUTPUT); // Sets the trigPin as an Output
  pinMode(PIN_ECHOSONAR, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  //servo
  // Attach servo to pin
  Servo1.attach(servoPin); 



}




void loop() {

  // sonar
  // Clears the trigPin
  digitalWrite(PIN_TRIGSONAR, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(PIN_TRIGSONAR, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGSONAR, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationSonar = pulseIn(PIN_ECHOSONAR, HIGH);
  
  // Calculating the distance
  distanceSonar = durationSonar*0.034/2;
  
  // Prints the distance on the Serial Monitor
  char buffer[100];
  sprintf(buffer, "Sonar Distance: %i cm", distanceSonar);
  Serial.println(buffer);
  //Serial.println("Sonar Distance: " + distanceSonar + " cm");



  // todo
  // make servo attack if distance is some value
  // from 0 to 180 to 0

  if(distanceSonar < 20){
    servoAttack();
    }

  

}
