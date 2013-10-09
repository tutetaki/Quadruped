/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

#include <Arduino.h>
#include <Servo.h>
#include <SimpleTimer.h>
#include <Wire.h>
#include <ArduinoNunchuk.h>
#include "servo_group.h"
#include "parameters.h"

ServoGroup servo_group = ServoGroup();
ArduinoNunchuk nunchuk = ArduinoNunchuk();

SimpleTimer timer = SimpleTimer();
float period;     // cycle from 0 to 1 indefinitely
long selector;    // take a random value every period

Behaviour *behaviours[] = {&lean, &idle};    // sorted array (highest to lowest priority)
Behaviour *winner_behaviour = &idle;
Leg legs[NBR_LEGS];

void setup() {
    Serial.begin(BAUDRATE);
    servo_group.attachAll();
    nunchuk.init();

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
    }
}

void subsume() {
    //obedientTask();          // execute user commands 
    //navigationTask();        // execute programmed path
    leanTask();
    idleTask(selector);    // default behaviour
    arbitrate();
}

void arbitrate() {
    for(int i=0; i < NBR_BEHAVIOUR; i++) {       // loop through tasks 
        if(behaviours[i] -> flag) {              // check the flag
            winner_behaviour = behaviours[i];    // output a winner behaviour
            break;                               // break at first enabled flag (subsume)
        }
    }
    servo_group.writeAll(winner_behaviour -> angles);    // the winner behaviour commands the servos 
}
