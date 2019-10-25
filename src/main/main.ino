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
int accelaration;

int lightAmount;

// modes
bool idleMode = true;
bool idleModeStatus = true;
bool idleStatus = true;
bool attackMode = false;
bool attackModeStatus = false;
bool attackStatus = false;
bool defendMode = false;
bool defendModeStatus = false;
bool defendStatus = false;
bool startleMode = false;
bool startleModeStatus = false;
bool startleStatus = false;


// servo
// Create a servo object 
Servo Servo1; 
Servo Servo2; 

// Mode functions
void initiateFunctionIdleMode(){
  Serial.println("IDLE MODE"); 
  resetAll();
  idleModeStatus = true;
  
  screenIdleMode();
  }


void initiateFunctionAttackMode(){
  Serial.println("ATTACK MODE"); 
  resetAll();
  attackModeStatus = true;
   
  screenAttackMode();
}
  
void repeaterFunctionAttackMode(){
  servo1Attack();
  }
  
void initiateFunctionDefendMode(){
  Serial.println("DEFEND MODE"); 
  resetAll();
  defendModeStatus = true;
  
  servo2Defend();
  screenDefendMode();
  }
  
void initiateFunctionStartleMode(){
  Serial.println("STARTLE MODE"); 
  resetAll();
  startleModeStatus = true;

  screenStartleMode();
  }



// servo 1
// Change servo to
void servo1Attack() {
  attackStatus = true;
  Servo1.write(180);
  delay(100);
  Servo1.write(0);
  attackStatus = false;
  }


// servo 2
// Change servo to
void servo2Defend() {
  defendModeStatus = true;
  Servo2.write(180);
  }


// Screen
void screenIdleMode(){
  
  }
void screenAttackMode(){

  }
void screenDefendMode(){

  }
void screenStartleMode(){

  }


  // sonar read
void sonarRead() {
  
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
  
  }

void resetAll() {
  Servo2.write(0);
  Servo1.write(0);
  
  idleMode = true;
  attackModeStatus = true;
  idleStatus = true;
  attackMode = false;
  attackModeStatus = false;
  attackStatus = false;
  defendMode = false;
  defendModeStatus = false;
  defendStatus = false;
  startleMode = false;
  startleModeStatus = false;
  startleStatus = false;
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
  
  //lets sonar read when not attacking
  if(!attackModeStatus){
    sonarRead();
    }


  //
  // Checks
  //
  
  // Changes mode to attack
  if(distanceSonar < 20){
    idleMode = false;
    attackMode = true;
    } else {
      attackMode = false;
      }

   // Changes mode to defend
  if(accelaration > 2) {
    idleMode = false;
    defendMode = true;
    } else {
      defendMode = false;
      }

  // Changes mode to startled
  if(lightAmount > 100) {
    idleMode = false;
    startleMode = true;
    } else {
      startleMode = false;
      }

   // Changes mode to idle
   if(!attackMode && !defendMode  && !startleMode) {
    idleMode = true;
    }



  //
  // Actions
  //


  // Does attackMode action every loop
  if(attackMode && !attackStatus){
    repeaterFunctionAttackMode();
    }


  if(attackMode && !attackModeStatus) {
    initiateFunctionStartleMode();
    } else {
      resetAll();
      }


  // Does defendMode action
  if(defendMode && !defendModeStatus) {
    initiateFunctionDefendMode();
    } 

  if(!defendMode) {
    resetAll();
    }


  // Does startleMode action and status switch
  if(startleMode && !startleModeStatus) {
    initiateFunctionStartleMode();
    } else {
      resetAll();
      }
  
  // Does idleMode action when idleMode is initiated
  if(idleMode && !idleModeStatus) {
    initiateFunctionIdleMode();
    } else {
      
      }
 



}
