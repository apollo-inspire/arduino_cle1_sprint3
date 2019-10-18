#include <Servo.h>
Servo leftmotor;
Servo rightmotor;
int pwmL,pwmR;

void setup()
{
leftmotor.attach(9); // af-motorshield servo 2
rightmotor.attach(10); // af-motorshield servo 1
}

void loop()
{
leftmotor.write(pwmL + 90); //  for use with continuous motor
rightmotor.write(pwmR +90);
}
