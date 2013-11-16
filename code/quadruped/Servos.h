#ifndef SERVOS_H
#define SERVOS_H

#include <Servo.h>
#include "Parameters.h"

class Servos {
    public:
        static const int pwl[NBR_SERVOS];
        static const int pwh[NBR_SERVOS];
        
        // attaches all servos variable to a pin
        void attachAll();
        
        // writes a pulse to all servos from the specified array
        void writeAll(int pulses[]);

    private:
        Servo _servos[NBR_SERVOS];
};

#endif
