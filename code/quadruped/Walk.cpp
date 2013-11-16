#include <Arduino.h>
#include <Wire.h>
#include <ArduinoNunchuk.h>
#include "Behaviour.h"
#include "Calculator.h"
#include "Walk.h"
#include "Parameters.h"
 
Walk::Walk(): Behaviour() {}

void Walk::task(ArduinoNunchuk nunchuk, float period) {
    // Read sensor
    nunchuk.update();
    
    // Calculate output
    int x_sensor = map(nunchuk.analogX, 0, 255, -127, 128) + NUNCHUCK_X_OFFSET;
    int y_sensor = map(nunchuk.analogY, 0, 255, -127, 128) + NUNCHUCK_Y_OFFSET;

    walk_samples[walk_sample_iterator] = sqrt(x_sensor*x_sensor+y_sensor*y_sensor);
    aas[aa_iterator] = atan2(y_sensor, x_sensor) * RAD_TO_DEG;
    if(aas[aa_iterator] < 0) {
        aas[aa_iterator] = Calculator::mapFloat(aas[aa_iterator], -179, 0, 181, 360);
    }
    
    float sum = 0;
    for(int i=0; i < NBR_SAMPLES; i++) {
        sum = sum + walk_samples[i];
    }
    float aasum = 0;
    for(int i=0; i < NBR_AA; i++) {
        aasum = aasum + aas[i];
    }

    float magnitude = sum / (float)NBR_SAMPLES;
    float direction = (aasum / (float)NBR_AA) * DEG_TO_RAD;
    if(direction > PI) {
        direction = Calculator::mapFloat(direction, PI, TWO_PI, -PI, 0);
    }
    
    if(walk_sample_iterator < NBR_SAMPLES) {
        walk_sample_iterator++;
    } else {
        walk_sample_iterator = 0;
    }
    if(aa_iterator < NBR_AA) {
        aa_iterator++;
    } else {
        aa_iterator = 0;
    }
    
    // Output control
    if(magnitude >= WALK_THRESHOLD) {
        magnitude = constrain(magnitude, WALK_THRESHOLD, WALK_MAXIMUM);
        center_x = magnitude*cos(direction)*period + Calculator::calculateX(period, GAIT_AMPLITUDE*sin(2*PI*period+PI), direction); 
        center_y = magnitude*sin(direction)*period + Calculator::calculateY(period, GAIT_AMPLITUDE*sin(2*PI*period+PI), direction);
        center_z = 0;
        
        int order[NBR_LEGS];
        if(direction >= -HALF_PI/2 && direction < HALF_PI/2) {               // 1,2,3,4
            order[0] = LEG1_ID; 
            order[1] = LEG2_ID;
            order[2] = LEG3_ID;
            order[3] = LEG4_ID;
        } else if(direction >= HALF_PI/2 && direction < 3*HALF_PI/2) {       // 2,3,4,1
            order[0] = LEG2_ID;
            order[1] = LEG3_ID;
            order[2] = LEG4_ID;
            order[3] = LEG1_ID;
        } else if(direction >= 3*HALF_PI/2 || direction < -3*HALF_PI/2) {    // 3,4,1,2
            order[0] = LEG3_ID;
            order[1] = LEG4_ID;
            order[2] = LEG1_ID;
            order[3] = LEG2_ID;
        } else if(direction >= -3*HALF_PI/2 && direction < -HALF_PI/2) {     // 4,1,2,3
            order[0] = LEG4_ID;
            order[1] = LEG1_ID;
            order[2] = LEG2_ID;
            order[3] = LEG3_ID;
        }

        int steps = 4;
        if(period > 0 && period <= 0.25) {
            x[order[0]] = Calculator::sign[order[0]][0]*DEFAULT_X+magnitude*cos(direction)*period*steps;
            y[order[0]] = Calculator::sign[order[0]][1]*DEFAULT_Y+magnitude*sin(direction)*period*steps;
            z[order[0]] = DEFAULT_Z-LEG_Z_LIFT*sin(PI*period*steps);

            x[order[1]] = Calculator::sign[order[1]][0]*DEFAULT_X;
            y[order[1]] = Calculator::sign[order[1]][1]*DEFAULT_Y;
            z[order[1]] = DEFAULT_Z;

            x[order[2]] = Calculator::sign[order[2]][0]*DEFAULT_X;
            y[order[2]] = Calculator::sign[order[2]][1]*DEFAULT_Y;
            z[order[2]] = DEFAULT_Z;

            x[order[3]] = Calculator::sign[order[3]][0]*DEFAULT_X;
            y[order[3]] = Calculator::sign[order[3]][1]*DEFAULT_Y;
            z[order[3]] = DEFAULT_Z;
        } else if(period > 0.25 && period <= 0.5) {
            x[order[0]] = Calculator::sign[order[0]][0]*DEFAULT_X+magnitude*cos(direction);
            y[order[0]] = Calculator::sign[order[0]][1]*DEFAULT_Y+magnitude*sin(direction);
            z[order[0]] = DEFAULT_Z;

            x[order[1]] = Calculator::sign[order[1]][0]*DEFAULT_X+magnitude*cos(direction)*(period-0.25)*steps;
            y[order[1]] = Calculator::sign[order[1]][1]*DEFAULT_Y+magnitude*sin(direction)*(period-0.25)*steps;
            z[order[1]] = DEFAULT_Z+LEG_Z_LIFT*sin(PI*period*steps);

            x[order[2]] = Calculator::sign[order[2]][0]*DEFAULT_X;
            y[order[2]] = Calculator::sign[order[2]][1]*DEFAULT_Y;
            z[order[2]] = DEFAULT_Z;

            x[order[3]] = Calculator::sign[order[3]][0]*DEFAULT_X;
            y[order[3]] = Calculator::sign[order[3]][1]*DEFAULT_Y;
            z[order[3]] = DEFAULT_Z;
        } else if(period > 0.5 && period <= 0.75) {
            x[order[0]] = Calculator::sign[order[0]][0]*DEFAULT_X+magnitude*cos(direction);
            y[order[0]] = Calculator::sign[order[0]][1]*DEFAULT_Y+magnitude*sin(direction);
            z[order[0]] = DEFAULT_Z;

            x[order[1]] = Calculator::sign[order[1]][0]*DEFAULT_X+magnitude*cos(direction);
            y[order[1]] = Calculator::sign[order[1]][1]*DEFAULT_Y+magnitude*sin(direction);
            z[order[1]] = DEFAULT_Z;

            x[order[2]] = Calculator::sign[order[2]][0]*DEFAULT_X+magnitude*cos(direction)*(period-0.5)*steps;
            y[order[2]] = Calculator::sign[order[2]][1]*DEFAULT_Y+magnitude*sin(direction)*(period-0.5)*steps;
            z[order[2]] = DEFAULT_Z-LEG_Z_LIFT*sin(PI*period*steps);

            x[order[3]] = Calculator::sign[order[3]][0]*DEFAULT_X;
            y[order[3]] = Calculator::sign[order[3]][1]*DEFAULT_Y;
            z[order[3]] = DEFAULT_Z;
        } else if(period > 0.75 && period <= 1) {
            x[order[0]] = Calculator::sign[order[0]][0]*DEFAULT_X+magnitude*cos(direction);
            y[order[0]] = Calculator::sign[order[0]][1]*DEFAULT_Y+magnitude*sin(direction);
            z[order[0]] = DEFAULT_Z;

            x[order[1]] = Calculator::sign[order[1]][0]*DEFAULT_X+magnitude*cos(direction);
            y[order[1]] = Calculator::sign[order[1]][1]*DEFAULT_Y+magnitude*sin(direction);
            z[order[1]] = DEFAULT_Z;

            x[order[2]] = Calculator::sign[order[2]][0]*DEFAULT_X+magnitude*cos(direction);
            y[order[2]] = Calculator::sign[order[2]][1]*DEFAULT_Y+magnitude*sin(direction);
            z[order[2]] = DEFAULT_Z;

            x[order[3]] = Calculator::sign[order[3]][0]*DEFAULT_X+magnitude*cos(direction)*(period-0.75)*steps;
            y[order[3]] = Calculator::sign[order[3]][1]*DEFAULT_Y+magnitude*sin(direction)*(period-0.75)*steps;
            z[order[3]] = DEFAULT_Z+LEG_Z_LIFT*sin(PI*period*steps);
        }
        
        setFlag(true);
        Calculator::calculatePulses(getPulses(), center_x, center_y, center_z, x, y, z);
    }
    else {
        setFlag(false);
    }

    Serial.print(x_sensor);
    Serial.print(",");
    Serial.print(y_sensor);
    Serial.print("\t");
    Serial.print(magnitude);
    Serial.print("\t");
    Serial.print(direction * RAD_TO_DEG);
    Serial.print("\t");
    Serial.print(direction);
    Serial.print("\t");
    float ze = atan2(y_sensor, x_sensor) * RAD_TO_DEG;
    if(ze < 0) {
        ze = Calculator::mapFloat(ze, -179, 0, 181, 360);
    }
    Serial.print(ze);
    Serial.print("\t");
    float zf = ze * DEG_TO_RAD;
    if(zf > PI) {
        zf = Calculator::mapFloat(zf, PI, TWO_PI, -PI, 0);
    }
    Serial.println(zf);
}
