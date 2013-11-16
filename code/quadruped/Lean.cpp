#include <Arduino.h>
#include <Wire.h>
#include <ArduinoNunchuk.h>
#include "Behaviour.h"
#include "Calculator.h"
#include "Lean.h"
#include "Parameters.h"
 
Lean::Lean(): Behaviour() {}

void Lean::task(ArduinoNunchuk nunchuk, float period) {
    // Read sensor
    nunchuk.update();
    
    // Calculate output
    int x_sensor = map(nunchuk.analogX, 0, 255, -127, 128) + NUNCHUCK_X_OFFSET;
    int y_sensor = map(nunchuk.analogY, 0, 255, -127, 128) + NUNCHUCK_Y_OFFSET;

    lean_samples[lean_sample_iterator] = sqrt(x_sensor*x_sensor+y_sensor*y_sensor);
    
    float sum = 0;
    for(int i=0; i < NBR_SAMPLES; i++) {
        sum = sum + lean_samples[i];
    }

    float magnitude = sum / (float)NBR_SAMPLES;
    float direction = atan2(y_sensor, x_sensor);
    
    if(lean_sample_iterator < NBR_SAMPLES) {
        lean_sample_iterator++;
    } else {
        lean_sample_iterator = 0;
    }
    
    // Output control
    if(magnitude >= LEAN_THRESHOLD && magnitude < WALK_THRESHOLD) {
        center_x = magnitude*cos(direction);
        center_y = magnitude*sin(direction);
        center_z = 0;
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
        setFlag(true);
        Calculator::calculatePulses(getPulses(), center_x, center_y, center_z, x, y, z);
    }
    else {
        setFlag(false);
    }
    
//    Serial.print(x_sensor);
//    Serial.print(",");
//    Serial.print(y_sensor);
//    Serial.print("\t");
//    Serial.print(magnitude);
//    Serial.print("\t");
//    Serial.print(direction);
//    Serial.print("\t");
//    Serial.println(direction * RAD_TO_DEG);
}
