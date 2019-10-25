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
int servoPin1 = 3;
int servoPin2 = 4;

//
int accelaration = 1;

// startle mode
bool idleMode = true;
bool idleStatus = true;
bool attackMode = false;
bool attackStatus = false;
bool defendMode = false;
bool defendStatus = false;
bool startleMode = false;
bool startleStatus = false;


// servo
// Create a servo object 
Servo Servo1; 
Servo Servo2; 


// servo 1
// Change servo to
void servo1Attack() {
  attackStatus = true;
  Serial.println("SERVO 1 ATTACK MODE"); 
  Servo1.write(0);
  delay(100);
  Servo1.write(180);
  delay(100);
  Servo1.write(0);
  attackStatus = false;
  }


// servo 2
// Change servo to
void servo2Defend() {
  Serial.println("SERVO 2 DEFEND MODE"); 
  defendStatus = true;
  Servo2.write(0);
  delay(100);
  Servo2.write(180);
  }


void servo2UnDefend() {
  Serial.println("SERVO 2 UNDEFEND MODE"); 
  Servo2.write(0);
  defendStatus = false;
  }


// Screen
void screenIdleMode(){
  idleStatus = true
  
  }
void screenAttackMode(){

  }
void screenDefendMode(){

  }
void screenStartleMode(){

  }


void setup() {

  // sonar
  pinMode(PIN_TRIGSONAR, OUTPUT); // Sets the trigPin as an Output
  pinMode(PIN_ECHOSONAR, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  //servo
  // Attach servo to pin
  Servo1.attach(servoPin1); 
  Servo2.attach(servoPin2); 

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


  // Checks
  // Changes state to attack
  if(distanceSonar < 20){
    idleMode = false;
    attackMode = true;
    } else {
      attackMode = false;
      idleMode = true;
      }

  if(accelaration > 2) {
    idleMode = false;
    defendMode = true;
    } else {
      defendMode = false;
      idleMode = true;
      }


  // Actions
  // Does idleMode action
  if(idleMode && !idleStatus) {
    screenIdleMode();    
    } else {
      idleStatus = false;
      }

 
  // Does attackMode action
  if(attackMode){
    servo1Attack();
    }

  // Does attackMode action and status swicth
  if(defendMode && !defendStatus) {
    servo2Defend();
    } else {
      servo2UnDefend();
      }

}
