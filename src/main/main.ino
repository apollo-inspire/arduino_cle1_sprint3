// fighting robot v3

// Libraries
#include <Servo.h> 
#include <LedControl.h>

// sonar
// defines pins numbers
#define PIN_TRIGSONAR1 9
#define PIN_ECHOSONAR1 10

#define PIN_TRIGSONAR2 7
#define PIN_ECHOSONAR2 8

// Screen
LedControl lc = LedControl(13,12,11,1);

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

int servoTimer;

// modes
bool idleMode = true;
bool idleModeStatus = false;
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

bool screenStateIdle = true;
bool screenStateCombat = false;
bool screenStateAttack = false;
bool screenStateDefend = false;
bool screenStateStartle = false;
bool screenStateAngry = false;


// Screen pixels

byte screenSpriteOff[] = {
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000
};

byte screenSpriteOn[] = {
B11111111,
B11111111,
B11111111,
B11101001,
B11101001,
B11101111,
B11101111,
B11111111
};

byte screenSpriteSad[] = {
B00000000,
B01000100,
B00010000,
B00010000,
B00000000,
B00111000,
B01000100,
B00000000
};
 
byte screenSpriteSmile[] = {
B00000000,
B01000100,
B00010000,
B00010000,
B00010000,
B01000100,
B00111000,
B00000000
};





byte screenSpriteIdle[] = {
B00000000,
B01100110,
B01100110,
B00000110,
B00000110,
B01100110,
B01100110,
B00000000
};

byte screenSpriteCombat[] = {
B00000000,
B00100110,
B00100110,
B00000110,
B00000110,
B00100110,
B00100110,
B00000000
};

byte screenSpriteAttack[] = {
B00100000,
B01010110,
B01010110,
B00100110,
B00100110,
B01010110,
B01010110,
B00100000
};

byte screenSpriteDefend[] = {
B00000000,
B01100110,
B01100110,
B00001001,
B00001001,
B01100110,
B01100110,
B00000000
};

byte screenSpriteStartle[] = {
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000
};

byte screenSpriteAngry[] = {
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000
};



// servo
// Create a servo object 
Servo Servo1; 
Servo Servo2; 

// Mode functions
void initiateFunctionIdleMode(){
  Serial.println("INITIATE IDLE"); 
  resetAll();
  idleMode = true;
  idleModeStatus = true;
  screenIdleMode();
  
  
  }

  void repeaterFunctionIdleMode(){
    Serial.println("idling");
  }


void initiateFunctionCombatMode() {
  Serial.println("INITIATE COMBAT");
  resetAll();
  combatMode = true;
  combatModeStatus = true;
  screenCombatkMode();
  
  
  }

void repeaterFunctionCombatMode() {
  Serial.println("fighting");
  
  }


void initiateFunctionAttack(){
  Serial.println("INITIATE ATTACK"); 
  attackModeStatus = true;

  
}
  
void repeaterFunctionAttack(){
  Serial.println("attacking");
  screenAttack();
  servo1Attack();
  //delay(100);
  //screenCombatkMode();
  
   
  }

  
void initiateFunctionDefend(){
  Serial.println("INITIATE DEFEND"); 
  defendModeStatus = true;
  screenDefend();
  
  servo2Defend();
  
  
  }

  void repeaterFunctionDefend(){
  Serial.println("defending");
  }
  
void initiateFunctionStartleMode(){
  Serial.println("INITIATE STARTLE"); 
  resetAll();
  startleMode = true;
  startleModeStatus = true;

  //screenStartleMode();
  }
  
void repeaterFunctionStartleMode(){
  Serial.println("starteling");
  }

void initiateFunctionAngryMode() {
  Serial.println("INITIATE ANRGY"); 
  resetAll();
  angryModeStatus = true;

  //screenAngryMode();
  }

void repeaterunctionAngryMode() {
  Serial.println("being angry");
  
  }




// servo 1
// Change servo to
void servo1Attack() {
  servoTimer++;
  //attackStatus = true;
  Serial.println(servoTimer);
  Serial.println("servo 1: start");
  if(servoTimer < 2) {
    Servo1.write(180);
    Serial.println("servo 1: 0");
    }  
  if(servoTimer == 4) {
    Servo1.write(0);
    Serial.println("servo 1: 180");
    }
  if(servoTimer == 8) {
    Servo1.write(180);
    Serial.println("servo 1: 0");
  }
  if(servoTimer > 12) {
    servoTimer = 0;
  }
  Serial.println("servo 1: end");
  //attackStatus = false;
}


// servo 2
// Change servo to
void servo2Defend() {
  defendStatus = true;
  Servo2.write(180);
  defendStatus = false;
  }


// Screen
void screenIdleMode(){
  resetScreenState();
  screenStateIdle = true;
  setSprite(screenSpriteIdle);

  }

void screenCombatkMode(){
  resetScreenState();
  screenStateCombat = true;
  setSprite(screenSpriteCombat);

  } 
void screenAttack(){
  resetScreenState();
  screenStateAttack = true;
  setSprite(screenSpriteAttack);


  }
void screenDefend(){
  resetScreenState();
  screenStateDefend = true;
  setSprite(screenSpriteDefend);

  }
 
void screenStartleMode(){
  resetScreenState();
  screenStateStartle = true;
  setSprite(screenSpriteStartle);
  }

void screenAngryMode(){
  resetScreenState();
  screenStateAngry = true;
  setSprite(screenSpriteAngry);
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

// Screen function
  void setSprite(byte *sprite){
    for(int r = 0; r < 8; r++){
        lc.setRow(0, r, sprite[r]);
    }
}
  
 
void resetAll() {
  Servo2.write(0);
  Servo1.write(180);

  lc.clearDisplay(0);
  
  idleMode = true;
  idleModeStatus = false;
  idleStatus = true;
  combatMode = false;
  combatModeStatus = false;
  combatStatus = false;
  attackMode = false;
  attackModeStatus = false;
  attackStatus = false;
  defendMode = false;
  defendModeStatus = false;
  defendStatus = false;
  startleMode = false;
  startleModeStatus = false;
  startleStatus = false;
  angryMode = false;
  angryModeStatus = false;
  angryStatus = false;

  screenStateIdle = true;
  screenStateIdle = false;
  screenStateCombat = false;
  screenStateAttack = false;
  screenStateDefend = false;
  screenStateStartle = false;
  screenStateAngry = false;
}

void resetScreenState() {
  screenStateIdle = false;
  screenStateIdle = false;
  screenStateCombat = false;
  screenStateAttack = false;
  screenStateDefend = false;
  screenStateStartle = false;
  screenStateAngry = false;
  }




void setup() {

  // sonar
  pinMode(PIN_TRIGSONAR1, OUTPUT); // Sets the trigPin as an Output
  pinMode(PIN_ECHOSONAR1, INPUT); // Sets the echoPin as an Input
  pinMode(PIN_TRIGSONAR2, OUTPUT);
  pinMode(PIN_ECHOSONAR2, INPUT);
  

  //servo
  // Attach servo to pin
  Servo1.attach(servo1Pin1); 
  Servo2.attach(servo1Pin2); 

  // Screen
  // Wakeup call
  lc.shutdown(0,false);
  // Brightness to a medium values
  lc.setIntensity(0, 8);
  // Clear display
  lc.clearDisplay(0);
  randomSeed(analogRead(0));

  Serial.begin(9600); // Starts the serial communication
  Serial.println("Started");

  initiateFunctionIdleMode();
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
  if(distanceSonar2 < 40){
    idleMode = false;
    attackMode = true;
    combatMode = true;
    } else {
      attackMode = false;
      }

   // Changes mode to defend
  if(distanceSonar2 > 3 && distanceSonar2 < 10) {
    idleMode = false;
    defendMode = true;
    combatMode = true;
    } else {
      defendMode = false;
      }

  if(!defendMode && !attackMode){
    combatMode = false;
  }

  
/*  
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
*/


   // Changes mode to idle
   if(!combatMode && !attackMode && !defendMode  && !startleMode && !angryMode) {
    idleMode = true;
    }




  //
  // Actions
  //

  if(!idleMode) {
    idleModeStatus = false;
    }

  if(idleMode && !idleModeStatus) {
    initiateFunctionIdleMode();
    }

  if(idleMode && !idleStatus) {
    repeaterFunctionIdleMode();
    }



  if(!idleMode && idleModeStatus) {
    resetAll();
    }
    




  if(combatMode && !combatModeStatus) {
    initiateFunctionCombatMode();
    }


  if(combatMode && !combatStatus) {
    repeaterFunctionCombatMode();
    }


  if(!combatMode && combatModeStatus) {
    resetAll();
    }




  if(attackMode && !attackModeStatus) {
    initiateFunctionAttack();
    }

  if(attackMode) {
    attackModeStatus = true;
    }
  
  if(attackMode && !attackStatus){
    repeaterFunctionAttack();
    }

  if(!attackMode && attackModeStatus) {
    attackMode = false;
    attackModeStatus = false;
    attackStatus = false;
    
    }





  if(defendMode && !defendModeStatus) {
    initiateFunctionDefend();
    }

 if(defendMode) {
    attackModeStatus = true;
    }

  if(defendMode && !defendStatus) {
    repeaterFunctionDefend();
    }

  if(!defendMode && defendModeStatus) {
    defendMode = false;
    defendModeStatus = false;
    defendStatus = false;
    }





  if(startleMode && !startleModeStatus) {
    initiateFunctionStartleMode();
    }


  if(startleMode && !startleStatus) {
    repeaterFunctionStartleMode();
    }

  if(!startleMode && startleModeStatus) {
    resetAll();
    }

}

// Lucas van der Vegt 2019
// EOF
