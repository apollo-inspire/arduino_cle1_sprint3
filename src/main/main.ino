// Libraries
#include <Servo.h> 


// sonar
// defines pins numbers
#define PIN_TRIGSONAR 9
#define PIN_ECHOSONAR 10

// sonar
// defines variables
long durationSonar1;
int distanceSonar1;

// servo
// Declare the Servo pin 
int servo1Pin1 = 3;
int servo1Pin2 = 4;

//
int accelaration;

int lightAmount;

// modes
bool idleMode = true;
bool idleModeStatus = true;
bool idleStatus = true;
bool combatMode = false;
bool combatModeStatus = false;
bool combatStatus = false;
bool attackMode = false;
bool attackModeStatus = false;
bool attackStatus = false;
bool defendMode = false;
bool defendModeStatus = false;
bool defendStatus = false;
bool startleMode = false;
bool startleModeStatus = false;
bool startleStatus = false;
bool angryMode = false;
bool angryModeStatus = false;
bool angryStatus = false;


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

  void repeaterFunctionIdleMode(){
    Serial.println("idling");
  }

void initiateFunctionCombatMode() {
  Serial.println("COMBAT MODE");
  resetAll();
  
  screenCombatkMode();
  }

void repeaterFunctionCombatMode() {
  Serial.println("fighting");
  
  }

void initiateFunctionAttack(){
  Serial.println("INITIATE ATTACK"); 
  attackModeStatus = true;
   
  screenAttack();
}
  
void repeaterFunctionAttack(){
  servo1Attack();
  Serial.println("attacking");
  }

  
void initiateFunctionDefend(){
  Serial.println("INITIATE DEFEND"); 
  defendModeStatus = true;
  
  servo2Defend();
  screenDefend();
  }

  void repeaterFunctionDefend(){
  Serial.println("defending");
  }
  
void initiateFunctionStartleMode(){
  Serial.println("STARTLE MODE"); 
  resetAll();
  startleModeStatus = true;

  screenStartleMode();
  }
  
void repeaterFunctionStartleMode(){
  Serial.println("starteling");
  }

void initiateFunctionAngryMode() {
  Serial.println("ANRGY MODE"); 
  resetAll();

  screenAngryMode();
  }

void repeaterunctionAngryMode() {
  Serial.println("angrying");
  
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

 void screenCombatkMode(){

  } 
void screenAttack(){

  }
void screenDefend(){

  }
 
void screenStartleMode(){

  }

void screenAngryMode(){
  
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
  durationSonar1 = pulseIn(PIN_ECHOSONAR, HIGH);
  
  // Calculating the distance
  distanceSonar1 = durationSonar1*0.034/2;
  
  // Prints the distance on the Serial Monitor
  char buffer[100];
  sprintf(buffer, "Sonar Distance: %i cm", distanceSonar1);
  Serial.println(buffer);
  //Serial.println("Sonar Distance: " + distanceSonar1 + " cm");
  
  }

void resetAll() {
  Servo2.write(0);
  Servo1.write(0);
  
  bool idleMode = true;
  bool idleModeStatus = true;
  bool idleStatus = true;
  bool combatMode = false;
  bool combatModeStatus = false;
  bool combatStatus = false;
  bool attackMode = false;
  bool attackModeStatus = false;
  bool attackStatus = false;
  bool defendMode = false;
  bool defendModeStatus = false;
  bool defendStatus = false;
  bool startleMode = false;
  bool startleModeStatus = false;
  bool startleStatus = false;
  bool angryMode = false;
  bool angryModeStatus = false;
  bool angryStatus = false;
}


void setup() {

  // sonar
  pinMode(PIN_TRIGSONAR, OUTPUT); // Sets the trigPin as an Output
  pinMode(PIN_ECHOSONAR, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  //servo
  // Attach servo to pin
  Servo1.attach(servo1Pin1); 
  Servo2.attach(servo1Pin2); 

}





void loop() {
  
  //lets sonar read when not attacking
  if(!attackStatus){
    sonarRead();
    }


  //
  // Checks
  //
  
  // Changes mode to attack
  if(distanceSonar1 < 20){
    idleMode = false;
    attackMode = true;
    combatMode = true;
    } else {
      attackMode = false;
      }

   // Changes mode to defend
  if(accelaration > 2) {
    idleMode = false;
    defendMode = true;
    combatMode = true;
    } else {
      defendMode = false;
      }

  // Changes mode to startled
  if(distanceSonar1 < 20) {
    idleMode = false;
    startleMode = true;
    } else {
      startleMode = false;
      }

  if(accelaration > 2) {
  idleMode = false;
  angrydMode = true;
  } else {
    angryMode = false;
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
    repeaterFunctionAttack();
    }


  if(attackMode && !attackModeStatus) {
    initiateFunctionAttack();
    } else {
      resetAll();
      }


  // Does defendMode action
  if(defendMode && !defendModeStatus) {
    initiateFunctionDefend();
    } 

  if(!defendMode) {
    resetAll();
    }

  if(defendMode && !defendStatus) {
    repeaterFunctionDefend();
    }


  // Does startleMode action and status switch
  if(startleMode && !startleModeStatus) {
    initiateFunctionStartleMode();
    } else {
      resetAll();
      }

  if(startleMode && !startleStatus) {
  repeaterFunctionStartleMode();
    }
  
  // Does idleMode action when idleMode is initiated
  if(idleMode && !idleModeStatus) {
    initiateFunctionIdleMode();
    } else {
      
      }

   if(idleMode && !idleStatus) {
    repeaterFunctionIdleMode();
    }
 
}
