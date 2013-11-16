#ifndef IDLE_H
#define IDLE_H

#include "Behaviour.h"

class Idle: public Behaviour {
    public:
        // constructor
        Idle();
        
        // Idle Behaviour (default, flag always TRUE): 
        //    Stands still. This is what the robot does when no other behaviour request the control.
        //    - default idle routine: the robot stands perfectly still.
        //    - routine 1: the center of the robot draw a circle while the legs stay put.
        //    - routine 2: the center of the robot draw a x-cross while the legs stay put.
        //    - routine 3: the center of the robot draw a +-cross while the legs stay put.
        //    - routine 4: the center of the robot goes up then down as if breathing.
        // TODO: Idle routine 5: the center of the robot turns 90° in one direction then 180° in the oposite and back to zero while the legs stay put.
        void task(int routine, float period);
};

#endif
