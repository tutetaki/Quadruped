#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include "Parameters.h"

class Behaviour {
    public:
        static int count;
        
        // constructor
        Behaviour();
        
        // puts the flag to the specified value
        void setFlag(bool f);
        
        // returns the flag
        bool getFlag();
        
        // returns the array of pulses
        int* getPulses();
        
    private:
        bool _flag;                 // inform if wants control or not
        int _pulses[NBR_SERVOS];    // pulses sent to servos
        
    protected:
        float center_x;      // x center position of the robot
        float center_y;      // y center position of the robot
        float center_z;      // z center position of the robot
        float x[NBR_LEGS];   // x positions of legs
        float y[NBR_LEGS];   // y positions of legs
        float z[NBR_LEGS];   // z positions of legs
};

#endif
