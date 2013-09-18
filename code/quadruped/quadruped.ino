/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

#include <Arduino.h>
#include <Servo.h>
#include <SimpleTimer.h>
#include "variables.h"

Servo Servos[NBR_SERVOS];
Leg legs[NBR_LEGS];

SimpleTimer timer;
long period;    // variable cycling from 0 to 1 indefinitely

Behaviour *behaviours[] = {&idle};    // sorted array (highest to lowest priority)
Behaviour *winner_behaviour = &idle;

void setup() {
    // Servos setup
    for( int i =0; i < NBR_SERVOS; i++) 
        Servos[i].attach(FIRST_SERVO_PIN +i, 600, 2400);
        
    // Timed actions setup
    timer.setInterval(50, subsume);     // Timer is triggered every 50 milliseconds
}

void loop() {
    period = (millis() % 1000) / 1000;
    timer.run();
    arbitrate();
}



void subsume() {
    //obedient_behaviour();      // execute user commands 
    //navigation_behaviour();    // execute programmed path
    idle_behaviour(42);          // execute random routines in place 
}

void arbitrate() {
    if(1){                                          // TODO: global flag to enable subsumption
        for(int i = 0; i < NBR_BEHAVIOUR; i++) {    // loop through tasks and check the flag
           if(behaviours[i]->flag)                  // ...
               winner_behaviour = behaviours[i];    // output winner behaviour
               break;                               // break at first enabled flag (subsume)
        }

        motors_command(winner_behaviour);           // the winner behaviour commands the motors 
    }
}


/* 
 * Utilities 
 */
void get_angles_from_positions(int angles[][NBR_JOINTS], Positions positions) {
    for(int i=0; i < NBR_LEGS; i++) {
        legs[i].x_offset = positions.x[i] - sqrt(CENTER_OFFSET*CENTER_OFFSET/2) - positions.center_x;
        legs[i].y_offset = positions.y[i] - sqrt(CENTER_OFFSET*CENTER_OFFSET/2) - positions.center_y;
        legs[i].z_offset = positions.z[i] + positions.center_z;

        legs[i].x = cal_x_prime(legs[i].x_offset, legs[i].y_offset, HALF_PI/2 + HALF_PI*i);
        legs[i].y = cal_y_prime(legs[i].x_offset, legs[i].y_offset, HALF_PI/2 + HALF_PI*i);
        legs[i].z = legs[i].z_offset;

        legs[i].u = sqrt(legs[i].x*legs[i].x + legs[i].y*legs[i].y);
        legs[i].n = sqrt((legs[i].u-L1)*(legs[i].u-L1) + legs[i].z*legs[i].z);
        legs[i].a[0] = acos((legs[i].z*legs[i].z+legs[4].n*legs[4].n-(legs[i].u-L1)*(legs[i].u-L1)) / (2*legs[i].z*legs[i].n));
        legs[i].a[1] = acos((legs[i].n*legs[i].n+L2*L2-L3*L3) / (2*legs[i].n*L2));
        legs[i].a[2] = acos((L2*L2+L3*L3-legs[i].n*legs[i].n) / (2*L2*L3));

        angles[i][JOINT1_ID] = ( atan(legs[i].y/legs[i].x) ) * RAD_TO_DEG;
        angles[i][JOINT2_ID] = ( legs[i].a[0] + legs[i].a[1] - HALF_PI ) * RAD_TO_DEG;
        angles[i][JOINT1_ID] = ( PI - legs[i].a[2] ) * RAD_TO_DEG;
    }
}

// Planar rotation (x -> x')
int cal_x_prime(int x, int y, float angle) {
    return x*cos(angle) + y*sin(angle);
}

int cal_y_prime(int x, int y, float angle) {
    return -x*sin(angle) + y*cos(angle);
}
