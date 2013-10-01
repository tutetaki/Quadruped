/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

#include <Servo.h> 
#define NBR_SERVOS 12

Servo servos[NBR_SERVOS];

int val = 90;

void setup() { 
    // Leg 1
    servos[0].attach(2, 760, 2560);
    servos[1].attach(3, 620, 2420);
    servos[2].attach(4, 700, 2500);
    // Leg 2
    servos[3].attach(5, 705, 2505);
    servos[4].attach(6, 700, 2500);
    servos[5].attach(7, 700, 2500);
    // Leg 3
    servos[6].attach(8, 600, 2400);
    servos[7].attach(9, 690, 2490);
    servos[8].attach(10, 660, 2460);
    // Leg 4
    servos[9].attach(11, 700, 2500);
    servos[10].attach(12, 645, 2445);
    servos[11].attach(13, 640, 2440);
} 

void loop() { 
    // Servos setup
    for(int i = 0; i < NBR_SERVOS; i++) {
    	servos[i].write(val);
    	delay(1000);
    }
} 
