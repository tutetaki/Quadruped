/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

#include <Arduino.h>
#include <Servo.h>
#include <SimpleTimer.h>
#include "variables.h"

Servo servos[NBR_SERVOS];
Leg leg;
Positions pos;             // inputs
int angles[NBR_JOINTS];    // angle values sent to servos

SimpleTimer timer;
float period;    // variable cycling from 0 to 1 indefinitely

void setup() {
    Serial.begin(9600);

    // Servos setup, centering  
    servos[0].attach(SERVO_1_PIN, 760, 2560);
    servos[1].attach(SERVO_2_PIN, 620, 2420);
    servos[2].attach(SERVO_3_PIN, 700, 2500);
        
    // Timed actions setup
    timer.setInterval(50, moveLeg);     // timer is triggered every 50 milliseconds
}

void loop() {
    pos.center_x = 0;
    pos.center_y = 0;
    pos.center_z = 0;
    pos.x = 90;
    pos.y = 90;
    pos.z = 90;

    period = (millis() % 1000) / 1000.0;
    timer.run();
}



void moveLeg() {
    leg.x_offset = pos.x - sqrt(CENTER_OFFSET*CENTER_OFFSET/2) - pos.center_x;
    leg.y_offset = pos.y - sqrt(CENTER_OFFSET*CENTER_OFFSET/2) - pos.center_y;
    leg.z_offset = pos.z + pos.center_z;

    leg.x = cal_x_prime(leg.x_offset, leg.y_offset, HALF_PI/2 + HALF_PI*LEG1_ID);
    leg.y = cal_y_prime(leg.x_offset, leg.y_offset, HALF_PI/2 + HALF_PI*LEG1_ID);
    leg.z = leg.z_offset;

    leg.u = sqrt(leg.x*leg.x + leg.y*leg.y);
    leg.n = sqrt((leg.u-L1)*(leg.u-L1) + leg.z*leg.z);
    leg.a[0] = acos((leg.z*leg.z+leg.n*leg.n-(leg.u-L1)*(leg.u-L1)) / (2*leg.z*leg.n));
    leg.a[1] = acos((leg.n*leg.n+L2*L2-L3*L3) / (2*leg.n*L2));
    leg.a[2] = acos((L2*L2+L3*L3-leg.n*leg.n) / (2*L2*L3));

    angles[0] = 90 + ( atan(leg.y/leg.x) ) * RAD_TO_DEG;
    angles[1] = 28 + ( leg.a[0] + leg.a[1] - HALF_PI ) * RAD_TO_DEG;
    angles[2] = 180 - ( PI - leg.a[2] ) * RAD_TO_DEG;

    servos[0].write(angles[0]);
    servos[1].write(angles[1]);
    servos[2].write(angles[2]);
    
    Serial.print(angles[0]);
    Serial.print("  ");
    Serial.print(angles[1]);
    Serial.print("  ");
    Serial.println(angles[2]);
}

// Planar rotation (x -> x')
int cal_x_prime(int x, int y, float angle) {
    return x*cos(angle) + y*sin(angle);
}
// Planar rotation (y -> y')
int cal_y_prime(int x, int y, float angle) {
    return -x*sin(angle) + y*cos(angle);
}
