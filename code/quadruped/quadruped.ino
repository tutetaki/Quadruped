/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

#include <Arduino.h>
#include <Servo.h>
#include <SimpleTimer.h>
#include "variables.h"

Servo servos[NBR_SERVOS];
Leg legs[NBR_LEGS];

SimpleTimer timer;
float period;    // variable cycling from 0 to 1 indefinitely
long randNumber;

Behaviour *behaviours[] = {&idle};    // sorted array (highest to lowest priority)
Behaviour *winnerBehaviour = &idle;


void setup() {
    Serial.begin(9600);
    // Servos setup, centering  
    servos[0].attach(SERVO_1_PIN, 760, 2560);
    servos[1].attach(SERVO_2_PIN, 620, 2420);
    servos[2].attach(SERVO_3_PIN, 700, 2500);

    servos[3].attach(SERVO_4_PIN, 705, 2505);
    servos[4].attach(SERVO_5_PIN, 700, 2500);
    servos[5].attach(SERVO_6_PIN, 700, 2500);

    servos[6].attach(SERVO_7_PIN, 600, 2400);
    servos[7].attach(SERVO_8_PIN, 690, 2490);
    servos[8].attach(SERVO_9_PIN, 660, 2460);

    servos[9].attach(SERVO_10_PIN, 700, 2500);
    servos[10].attach(SERVO_11_PIN, 645, 2445);
    servos[11].attach(SERVO_12_PIN, 640, 2440);

    // Timed actions setup
    timer.setInterval(SPEED, countTime);
    timer.setInterval(50, subsume);      // timer is triggered every 50 milliseconds
}

void loop() {
    timer.run();
    arbitrate();
}


void countTime() {
    period += FLUIDITY;
    if(period > 1) {
        period = 0;
        randNumber = random(20);
        Serial.println(randNumber);
    }
    Serial.println(period, 3);
}

void subsume() {
    //obedientTask();          // execute user commands 
    //navigationTask();        // execute programmed path
    idleTask(randNumber);    // execute default routines
}

void arbitrate() {
    for(int i=0; i < NBR_BEHAVIOUR; i++) {    // loop through tasks and check the flag
        if(behaviours[i] -> flag) {               // ...
            winnerBehaviour = behaviours[i];    // output winner behaviour
            break;                              // break at first enabled flag (subsume)
        }
    }
    commandServos(winnerBehaviour);             // the winner behaviour commands the servos 
}
