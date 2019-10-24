// Libraries
#include <Servo.h> 





// sonar
// defines pins numbers
const int trigPinSonar = 9;
const int echoPinSonar = 10;

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
  Serial.print("SERVO ATTACK MODE"); 
  Servo1.write(0);
  delay(100);
  Servo1.write(180);
  delay(100);
  Servo1.write(0);
  delay(100);
  }




void setup() {

  // sonar
  pinMode(trigPinSonar, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinSonar, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  //servo
  // Attach servo to pin
  Servo1.attach(servoPin); 



}




void loop() {

  // sonar
  // Clears the trigPin
  digitalWrite(trigPinSonar, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinSonar, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinSonar, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationSonar = pulseIn(echoPinSonar, HIGH);
  
  // Calculating the distance
  distanceSonar = durationSonar*0.034/2;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Sonar Distance: ");
  Serial.println(distanceSonar);



  // todo
  // make servo attack if distance is some value
  // from 0 to 180 to 0

  if(distanceSonar < 20){
    servoAttack();
    }

  

}
