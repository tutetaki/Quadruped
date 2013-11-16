#include <Arduino.h>
#include "Behaviour.h"
#include "Calculator.h"
#include "Idle.h"
#include "Parameters.h"
 
Idle::Idle(): Behaviour() {}

void Idle::task(int routine, float period) {
    int steps, stretchAmplitude;
    
    // Calculate output
    switch (routine) {
        case 1:    // Circle pattern, change the sign to change rotation direction
            steps = 2;
            stretchAmplitude = 60;
            if(period > 0 && period <= 0.5) {
                center_x = stretchAmplitude*period*cos(2*PI*period*steps);
                center_y = stretchAmplitude*period*sin(2*PI*period*steps); 
                center_z = 0;
            } else if(period > 0.5 && period <= 1) {
                center_x = stretchAmplitude*(1-period)*cos(2*PI*(period-1/steps)*steps);
                center_y = stretchAmplitude*(1-period)*sin(2*PI*(period-1/steps)*steps);
                center_z = 0;
            }
            break;
        case 2:    // Diagonal cross pattern
            steps = 2;
            stretchAmplitude = 35;
            if(period > 0 && period <= 0.5) {
                center_x = stretchAmplitude*sin(2*PI*period*steps);
                center_y = stretchAmplitude*sin(2*PI*period*steps); 
                center_z = 0;
            } else if(period > 0.5 && period <= 1) {
                center_x = stretchAmplitude*sin(2*PI*(period-1/steps)*steps);
                center_y = -stretchAmplitude*sin(2*PI*(period-1/steps)*steps);
                center_z = 0;
            }
            break;
        case 3:    // Greek cross pattern
            steps = 2;
            stretchAmplitude = 35;
            if(period > 0 && period <= 0.5) {
                center_x = 0;
                center_y = stretchAmplitude*sin(2*PI*period*steps); 
                center_z = 0;
            } else if(period > 0.5 && period <= 1) {
                center_x = stretchAmplitude*sin(2*PI*(period-1/steps)*steps);
                center_y = 0; 
                center_z = 0;
            }
            break;
        case 4:     // Breath pattern
            stretchAmplitude = 10;
            center_x = 0;
            center_y = 0; 
            center_z = stretchAmplitude*sin(2*PI*period)*sqrt(period);
            break;
        default:    // Stand still
            center_x = 0;
            center_y = 0; 
            center_z = 0;
    } 
    x[LEG1_ID] = DEFAULT_X;
    y[LEG1_ID] = DEFAULT_Y;
    z[LEG1_ID] = DEFAULT_Z;
    x[LEG2_ID] = -DEFAULT_X;
    y[LEG2_ID] = DEFAULT_Y;
    z[LEG2_ID] = DEFAULT_Z;
    x[LEG3_ID] = -DEFAULT_X;
    y[LEG3_ID] = -DEFAULT_Y;
    z[LEG3_ID] = DEFAULT_Z;
    x[LEG4_ID] = DEFAULT_X;
    y[LEG4_ID] = -DEFAULT_Y;
    z[LEG4_ID] = DEFAULT_Z;
    
    // Output control
    setFlag(true);    // always true
    Calculator::calculatePulses(getPulses(), center_x, center_y, center_z, x, y, z);
    
//    Serial.print(routine);
//    Serial.print("\t");
//    Serial.println(period);
}
