#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
    public:
        static const int sign[][2];
        
        // maps a number from one range to another; handle floats
        static float mapFloat(float x, float in_min, float in_max, float out_min, float out_max);
       
        // planar rotation (x -> x')
        static float calculateXPrime(float x, float y, float angle);
        
        // planar rotation (y -> y')
        static float calculateYPrime(float x, float y, float angle);
        
        // planar rotation (x' -> x)
        static float calculateX(float xPrime, float yPrime, float angle);
        
        // planar rotation (y' -> y)
        static float calculateY(float xPrime, float yPrime, float angle);
        
        // calculates the pulses from the specified positions 
        static void calculatePulses(int pulses[], float center_x, float center_y, float center_z, float x_input[], float y_input[], float z_input[]);
};

#endif
