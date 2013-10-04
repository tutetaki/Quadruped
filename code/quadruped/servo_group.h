/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

#ifndef SERVO_GROUP_H
#define SERVO_GROUP_H

#include <Arduino.h>
#include <Servo.h>
#include "parameters.h"

//
//
class ServoGroup {
    public:
        void attachAll();
        void writeAll(int angles[NBR_SERVOS]);

    private:
        Servo servos_[NBR_SERVOS];
};

#endif
