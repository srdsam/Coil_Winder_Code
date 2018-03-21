/* 
speed is in rpm 
steps is literal. Positive is forwards, negative backwards.
*/
int step1 = 200;
int speed1 = 40;


int step2 = 200;
int speed2 = 40;
/*
sets outputs
*/

int pin3 = 3;
int pin4 = 4;

int pin6 = 6;
int pin7 = 7;

/*
importing library
*/
#include <Stepper.h>
/*
Stepper(turns per revolution, then the two (or four) pins attatched the motor)
assume motor2 is swedish screw and motor1 is twister.
*/
Stepper motor1 = Stepper(200, pin3, pin4);
Stepper motor2 = Stepper(200, pin6, pin7);

/*
Initialising counting turns and variables. Turns will be calculated based upon 
number of steps per loop.
*/
int loops = 0;
int motor1steps = 0;
int motor2steps = 0;
int endpoint;
int state;

void setup(){
  motor1.setSpeed(speed1);
  motor2.setSpeed(speed2);
  Serial.begin(9600);
}
void loop(){
  /*
  When step is called, the next command will not follow until mechanical motion complete
  e.g. 1rpm called on step(1) would take 1 minute to finish, until the next line of code
  is processed. 
  */
  delay(1000);
  motor1.step(step1);
  motor2.step(step2);
  delay(500);
      /* 
      The endpoint can be done by steps of motor or number of loops. Program is finished by
      endlessly looping 1. 
      */
}
