#include <Arduino.h>
#include "Servos.h"
#include "Calculator.h"
#include "Parameters.h"

const int Calculator::sign[][2] = {{1,1}, {-1,1}, {-1,-1}, {1,-1}};

float Calculator::mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float Calculator::calculateXPrime(float x, float y, float angle) {
    return x*cos(angle) + y*sin(angle);
}

float Calculator::calculateYPrime(float x, float y, float angle) {
    return -x*sin(angle) + y*cos(angle);
}

// Planar rotation (x' -> x)
float Calculator::calculateX(float xPrime, float yPrime, float angle) {
    return xPrime*cos(angle) - yPrime*sin(angle);
}
// Planar rotation (y' -> y)
float Calculator::calculateY(float xPrime, float yPrime, float angle) {
    return xPrime*sin(angle) + yPrime*cos(angle);
}

void Calculator::calculatePulses(int pulses[], float center_x, float center_y, float center_z, float x_input[], float y_input[], float z_input[]) {
    for(int i=0; i < NBR_LEGS; i++) {
        float x_offset = x_input[i] - Calculator::sign[i][0]*sqrt(CENTER_OFFSET*CENTER_OFFSET/2) - center_x;
        float y_offset = y_input[i] - Calculator::sign[i][1]*sqrt(CENTER_OFFSET*CENTER_OFFSET/2) - center_y;
        float z_offset = z_input[i] + center_z;
    
        float x = Calculator::calculateXPrime(x_offset, y_offset, HALF_PI/2 + HALF_PI*i);
        float y = Calculator::calculateYPrime(x_offset, y_offset, HALF_PI/2 + HALF_PI*i);
        float z = z_offset;
        
        float u = sqrt(x*x + y*y) - L1;
        float n = sqrt(u*u + z*z);
        float a1 = acos((z*z+n*n-u*u) / (2*z*n));
        float a2 = acos((n*n+L2*L2-L3*L3) / (2*n*L2));
        
        float alpha = atan(x/y); if(y < 0) { alpha += PI; }
        float beta = a1 + a2;
        float gamma = acos((L2*L2+L3*L3-n*n) / (2*L2*L3));
        
        // Map pulses from angles
        pulses[NBR_JOINTS*i] = Calculator::mapFloat(alpha * RAD_TO_DEG, 0, 180, Servos::pwl[NBR_JOINTS*i], Servos::pwh[NBR_JOINTS*i]);
        pulses[NBR_JOINTS*i+1] = Calculator::mapFloat(beta * RAD_TO_DEG, 0, 180, Servos::pwl[NBR_JOINTS*i+1], Servos::pwh[NBR_JOINTS*i+1]);
        pulses[NBR_JOINTS*i+2] = Calculator::mapFloat(gamma * RAD_TO_DEG, 0, 180, Servos::pwl[NBR_JOINTS*i+2], Servos::pwh[NBR_JOINTS*i+2]);
    }
}
