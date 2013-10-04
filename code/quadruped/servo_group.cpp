/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

#include <Arduino.h>
#include <Servo.h>
#include "servo_group.h"
#include "parameters.h"

void ServoGroup::attachAll() {
    Serial.println("attachAll");
    ServoGroup::servos_[0].attach(PIN_SERVO_1, 760, 2560);
    ServoGroup::servos_[1].attach(PIN_SERVO_2, 620, 2420);
    ServoGroup::servos_[2].attach(PIN_SERVO_3, 700, 2500);

    ServoGroup::servos_[3].attach(PIN_SERVO_4, 705, 2505);
    ServoGroup::servos_[4].attach(PIN_SERVO_5, 700, 2500);
    ServoGroup::servos_[5].attach(PIN_SERVO_6, 700, 2500);

    ServoGroup::servos_[6].attach(PIN_SERVO_7, 600, 2400);
    ServoGroup::servos_[7].attach(PIN_SERVO_8, 690, 2490);
    ServoGroup::servos_[8].attach(PIN_SERVO_9, 660, 2460);

    ServoGroup::servos_[9].attach(PIN_SERVO_10, 700, 2500);
    ServoGroup::servos_[10].attach(PIN_SERVO_11, 645, 2445);
    ServoGroup::servos_[11].attach(PIN_SERVO_12, 640, 2440);
    Serial.println("/attachAll");
    // ServoGroup::writeAll();
}

void ServoGroup::writeAll(int angles[NBR_SERVOS]) {
    for(int i=0; i < NBR_SERVOS; i++) {
        ServoGroup::servos_[i].write(angles[i]);
    }
}

