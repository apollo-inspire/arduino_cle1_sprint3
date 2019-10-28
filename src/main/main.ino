// Libraries
#include <Servo.h> 


// sonar
// defines pins numbers
#define PIN_TRIGSONAR1 9
#define PIN_ECHOSONAR1 10

#define PIN_TRIGSONAR2 7
#define PIN_ECHOSONAR2 8


// sonar
// defines variables
long durationSonar1;
int distanceSonar1;

long durationSonar2;
int distanceSonar2;

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
  Serial.println("INITIATE IDLE"); 
  resetAll();
  idleModeStatus = true;
  
  screenIdleMode();
  }

  void repeaterFunctionIdleMode(){
    Serial.println("idling");
  }


void initiateFunctionCombatMode() {
  Serial.println("INITIATE COMBAT");
  resetAll();
  combatModeStatus = true;
  
  
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
  Serial.println("INITIATE STARTLE"); 
  resetAll();
  startleModeStatus = true;

  screenStartleMode();
  }
  
void repeaterFunctionStartleMode(){
  Serial.println("starteling");
  }

void initiateFunctionAngryMode() {
  Serial.println("INITIATE ANRGY"); 
  resetAll();
  angryModeStatus = true;

  screenAngryMode();
  }

void repeaterunctionAngryMode() {
  Serial.println("being angry");
  
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
void sonar1Read() {
  
  // Clears the trigPin
  digitalWrite(PIN_TRIGSONAR1, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(PIN_TRIGSONAR1, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGSONAR1, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationSonar1 = pulseIn(PIN_ECHOSONAR1, HIGH);
  
  // Calculating the distance
  distanceSonar1 = durationSonar1*0.034/2;
  
  // Prints the distance on the Serial Monitor
  char buffer[100];
  sprintf(buffer, "Sonar1 Distance: %i cm", distanceSonar1);
  Serial.println(buffer);
  
  }


void sonar2Read() {
  
  // Clears the trigPin
  digitalWrite(PIN_TRIGSONAR2, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(PIN_TRIGSONAR2, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGSONAR2, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationSonar2 = pulseIn(PIN_ECHOSONAR2, HIGH);
  
  // Calculating the distance
  distanceSonar2 = durationSonar2*0.034/2;
  
  // Prints the distance on the Serial Monitor
  char buffer[100];
  sprintf(buffer, "Sonar2 Distance: %i cm", distanceSonar2);
  Serial.println(buffer);

  
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
  pinMode(PIN_TRIGSONAR1, OUTPUT); // Sets the trigPin as an Output
  pinMode(PIN_ECHOSONAR1, INPUT); // Sets the echoPin as an Input
  pinMode(PIN_TRIGSONAR2, OUTPUT);
  pinMode(PIN_ECHOSONAR2, INPUT);
  Serial.begin(9600); // Starts the serial communication

  //servo
  // Attach servo to pin
  Servo1.attach(servo1Pin1); 
  Servo2.attach(servo1Pin2); 

}





void loop() {
  
  //lets sonar read when not attacking
  if(!attackStatus){
    sonar1Read();
    sonar2Read();
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
  if(distanceSonar2 < 20) {
    idleMode = false;
    defendMode = true;
    combatMode = true;
    } else {
      defendMode = false;
      }

  if(!defendMode && !attackMode){
    combatMode = false;
  }
  
  // Changes mode to startled
  if(accelaration > 20) {
    idleMode = false;
    startleMode = true;
    } else {
      startleMode = false;
      }

  if(accelaration > 2) {
    idleMode = false;
    angryMode = true;
    } else {
      angryMode = false;
      }


   // Changes mode to idle
   if(!combatMode && !attackMode && !defendMode  && !startleMode && !angryMode) {
    idleMode = true;
    }




  //
  // Actions
  //



  if(combatMode && !combatStatus) {
    repeaterFunctionCombatMode();
    }

  if(combatMode && !combatModeStatus) {
    initiateFunctionCombatMode();
    }

  if(!combatMode && combatModeStatus) {
    resetAll();
    }



  
  if(attackMode && !attackStatus){
    repeaterFunctionAttack();
    }


  if(attackMode && !attackModeStatus) {
    initiateFunctionAttack();
    }

  if(!attackMode && attackModeStatus) {
    resetAll();
    }





  if(defendMode && !defendStatus) {
    repeaterFunctionDefend();
    }

  if(defendMode && !defendModeStatus) {
    initiateFunctionDefend();
    }

  if(!defendMode && defendModeStatus) {
    resetAll();
    }



  if(startleMode && !startleStatus) {
    repeaterFunctionStartleMode();
    }

  if(startleMode && !startleModeStatus) {
    initiateFunctionStartleMode();
    }

  if(!startleMode && startleModeStatus) {
    resetAll();
    }




  if(idleMode && !idleStatus) {
    repeaterFunctionIdleMode();
    }

  if(idleMode && !idleModeStatus) {
    initiateFunctionIdleMode();
    }

  if(!idleMode && idleModeStatus) {
    resetAll();
    }
    
 
}
