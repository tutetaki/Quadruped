/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

Behaviour lean;
int lean_samples[NBR_SAMPLES];
int lean_sample_iterator = 0;

/*
 * Lean Behaviour : 
 *    Leans in a given direction.
 */
void leanTask() {
    nunchuk.update();

    // Calculate outputs
    int x = map(nunchuk.analogX, 0, 255, -127, 128) + NUNCHUCK_X_OFFSET;
    int y = map(nunchuk.analogY, 0, 255, -127, 128) + NUNCHUCK_Y_OFFSET;

    lean_samples[lean_sample_iterator] = sqrt(x*x+y*y);
    
    int sum = 0;
    for(int i=0; i < NBR_SAMPLES; i++) {
        sum = sum + lean_samples[i];
    }

    int magnitude = sum/NBR_SAMPLES;
    float direction = atan2(y,x) + PI/2;
    
    if(lean_sample_iterator < NBR_SAMPLES) {
        lean_sample_iterator++;
    } else {
        lean_sample_iterator = 0;
    }

    // Output commands
    if(magnitude > LEAN_THRESHOLD && magnitude <= WALK_THRESHOLD) {
        lean.state.center_x = magnitude*cos(direction);
        lean.state.center_y = magnitude*sin(direction);
        lean.state.center_z = 0;
        lean.state.x[LEG1_ID] = DEFAULT_X;
        lean.state.y[LEG1_ID] = DEFAULT_Y;
        lean.state.z[LEG1_ID] = DEFAULT_Z;
        lean.state.x[LEG2_ID] = -DEFAULT_X;
        lean.state.y[LEG2_ID] = DEFAULT_Y;
        lean.state.z[LEG2_ID] = DEFAULT_Z;
        lean.state.x[LEG3_ID] = -DEFAULT_X;
        lean.state.y[LEG3_ID] = -DEFAULT_Y;
        lean.state.z[LEG3_ID] = DEFAULT_Z;
        lean.state.x[LEG4_ID] = DEFAULT_X;
        lean.state.y[LEG4_ID] = -DEFAULT_Y;
        lean.state.z[LEG4_ID] = DEFAULT_Z;
        lean.flag = true;
        calculateAnglesFromState(lean.angles, lean.state);
    }
    else {
        lean.flag = false;
    }
    
    Serial.print(x);
    Serial.print(",");
    Serial.print(y);
    Serial.print(",");
    Serial.print(magnitude);
    Serial.print(",");
    Serial.println(direction * RAD_TO_DEG);
}
