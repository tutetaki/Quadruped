#ifndef LEAN_H
#define LEAN_H

#include "Behaviour.h"

class Lean: public Behaviour {
    public:
        // constructor
        Lean();
        
        // Lean Behaviour:
        //    Leans in a given direction.
        void task(ArduinoNunchuk nunchuk, float period);
        
    private:
        int lean_samples[NBR_SAMPLES];
        int lean_sample_iterator;
};

#endif
