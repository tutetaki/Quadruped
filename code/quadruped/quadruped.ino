/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

#include <Arduino.h>
#include <Servo.h>
#include <SimpleTimer.h>
#include "servo_group.h"
#include "parameters.h"

ServoGroup servo_group = ServoGroup();
Leg legs[NBR_LEGS];

SimpleTimer timer;
float period;      // cycle from 0 to 1 indefinitely
long selector;    // take a random value every period

Behaviour *behaviours[] = {&idle};    // sorted array (highest to lowest priority)
Behaviour *winner_behaviour = &idle;


void setup() {
    Serial.begin(BAUDRATE);
    servo_group.attachAll();

    // Timed actions setup
    timer.setInterval(SPEED, markTime);
    timer.setInterval(50, subsume);
}

void loop() {
    timer.run();
    // arbitrate();
}


void markTime() {
    period += STEP;
    if(period > 1) {
        period = 0;
        selector = random(10);
        Serial.println(selector);
    }
    Serial.println(period, 3);
}

void subsume() {
    //obedientTask();          // execute user commands 
    //navigationTask();        // execute programmed path
    idleTask(selector);    // execute default routines

}

void arbitrate() {
    for(int i=0; i < NBR_BEHAVIOUR; i++) {      // loop through tasks and check the flag
        if(behaviours[i] -> flag) {             // ...
            winner_behaviour = behaviours[i];    // output winner behaviour
            break;                              // break at first enabled flag (subsume)
        }
    }
    servo_group.writeAll(winner_behaviour->angles);    // the winner behaviour commands the servos 
}
