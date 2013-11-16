#include <Arduino.h>
#include <Servo.h>
#include <SimpleTimer.h>
#include <Wire.h>
#include <ArduinoNunchuk.h>
#include "Servos.h"
#include "Behaviour.h"
#include "Idle.h"
#include "Lean.h"
#include "Walk.h"
#include "Parameters.h"

Servos servos;
ArduinoNunchuk nunchuk;

SimpleTimer timer;
float period;     // cycle from 0 to 1 indefinitely
long selector;    // take a random value every period

// Behaviours
Idle idle;
Lean lean;
Walk walk;
Behaviour* behaviours[] = {&walk, &lean, &idle};    // sorted array (highest to lowest priority)
Behaviour* winner;

void setup() { 
    Serial.begin(BAUDRATE);

    servos.attachAll();
    nunchuk.init();
    
    // Timed actions setup
    timer.setInterval(SPEED, markTime);
    timer.setInterval(50, subsume);
}

void loop() {     
    timer.run();
} 

void markTime() {
    period += STEP;
    if(period > 1) { 
        period = 0; 
        selector = random(5);
    }
}

void subsume() {
    walk.task(nunchuk, period);
    lean.task(nunchuk, period);
    idle.task(selector, period);    // default behaviour
    arbitrate();
}

void arbitrate() {   
    for(int i=0; i < Behaviour::count; i++) {       // loop through tasks 
        if(behaviours[i] -> getFlag() == true) {    // check the flag
            winner = behaviours[i];                 // output a winner behaviour
            break;                                  // break at first enabled flag (subsume)
        }
    }
    servos.writeAll(winner -> getPulses());         // the winner behaviour commands the servos 
}
