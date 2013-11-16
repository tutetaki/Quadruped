#ifndef WALK_H
#define WALK_H

#include "Behaviour.h"

class Walk: public Behaviour {
    public:
        // constructor
        Walk();
        
        // Walk Behaviour:
        //    Walks in a given direction.
        void task(ArduinoNunchuk nunchuk, float period);
        
    private:
        int walk_samples[NBR_SAMPLES];
        int walk_sample_iterator;
        int aas[NBR_AA];
        int aa_iterator;
};

#endif
