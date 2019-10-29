/*  
 *   Play pong on an 8x8 matrix - project from itopen.it
 */
 
#include <LedControl.h>
 


 
byte sad[] = {
B00000000,
B01000100,
B00010000,
B00010000,
B00000000,
B00111000,
B01000100,
B00000000
};
 
byte smile[] = {
B00000000,
B01000100,
B00010000,
B00010000,
B00010000,
B01000100,
B00111000,
B00000000
};


LedControl lc = LedControl(13,12,11,1);


void setSprite(byte *sprite){
    for(int r = 0; r < 8; r++){
        lc.setRow(0, r, sprite[r]);
    }
}
 
void gameOver() {
    setSprite(sad);
    delay(1500);
    lc.clearDisplay(0);
}

void gameYes() {
    setSprite(smile);
    delay(1500);
    lc.clearDisplay(0);
}
 
 
void setup() {
  // The MAX72XX is in power-saving mode on startup,
  // we have to do a wakeup call
  lc.shutdown(0,false);
  // Set the brightness to a medium values
  lc.setIntensity(0, 8);
  // and clear the display
  lc.clearDisplay(0);
  randomSeed(analogRead(0));
  
  Serial.begin(9600);
  Serial.println("Started");

}
 
void loop() {
    delay(1000);
    gameOver();
    delay(1000);
    gameYes();
    }
