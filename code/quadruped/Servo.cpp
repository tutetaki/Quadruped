#include <Servo.h>
#include "Servos.h"
#include "Parameters.h"
#include <Arduino.h>

const int Servos::pwl[NBR_SERVOS] = {760, 620, 700, 705, 700, 700, 600, 690, 660, 700, 645, 640};
const int Servos::pwh[NBR_SERVOS] = {2560, 2420, 2500, 2505, 2500, 2500, 2400, 2490, 2460, 2500, 2445, 2440};

void Servos::attachAll() {
    // Leg 1
    _servos[0].attach(PIN_SERVO_1, Servos::pwl[0], Servos::pwh[0]);
    _servos[1].attach(PIN_SERVO_2, Servos::pwl[1], Servos::pwh[1]);
    _servos[2].attach(PIN_SERVO_3, Servos::pwl[2], Servos::pwh[2]);
    // Leg 2
    _servos[3].attach(PIN_SERVO_4, Servos::pwl[3], Servos::pwh[3]);
    _servos[4].attach(PIN_SERVO_5, Servos::pwl[4], Servos::pwh[4]);
    _servos[5].attach(PIN_SERVO_6, Servos::pwl[5], Servos::pwh[5]);
    // Leg 3
    _servos[6].attach(PIN_SERVO_7, Servos::pwl[6], Servos::pwh[6]);
    _servos[7].attach(PIN_SERVO_8, Servos::pwl[7], Servos::pwh[7]);
    _servos[8].attach(PIN_SERVO_9, Servos::pwl[8], Servos::pwh[8]);
    // Leg 4
    _servos[9].attach(PIN_SERVO_10, Servos::pwl[9], Servos::pwh[9]);
    _servos[10].attach(PIN_SERVO_11, Servos::pwl[10], Servos::pwh[10]);
    _servos[11].attach(PIN_SERVO_12, Servos::pwl[11], Servos::pwh[11]);
}

void Servos::writeAll(int pulses[]) {
    for(int i=0; i < NBR_SERVOS; i++) {
        _servos[i].writeMicroseconds(pulses[i]);
    }
//    for(int i=0; i < NBR_SERVOS; i++) {
//        Serial.print(pulses[i]);
//        Serial.print("\t");
//    }
//    Serial.println();
}
