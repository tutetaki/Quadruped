/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

Behaviour idle;

/*
 * Idle Behaviour (default, flag always TRUE): 
 *    Stands still. This is what the robot does when no other behaviour request the control.
 *    - Default idle routine: the robot stands perfectly still.
 *    - Idle routine 1: The center of the robot draw a circle while the legs stay put.
 *    - Idle routine 2: The center of the robot draw a x-cross while the legs stay put.
 *    - Idle routine 3: The center of the robot draw a +-cross while the legs stay put.
 *    - Idle routine 4: The center of the robot goes up then down as if breathing.
 * TODO: Idle routine 5: The center of the robot turns 90° in one direction then 180° in the opstateite and back to zero while the legs stay put.
 */
void idleTask(int routine) {
    int steps;
    int stretchAmplitude;
    
    switch (routine) {
        case 1:    // Circle pattern, change the sign to change rotation direction
            stretchAmplitude = 30;
            idle.state.center_x = stretchAmplitude*cos(2*PI*period);
            idle.state.center_y = 1 * stretchAmplitude*sin(2*PI*period);
            idle.state.center_z = 0;
            break;
        case 2:    // Cross pattern
            steps = 2;
            stretchAmplitude = 35;
            if(period > 0 && period <= 0.5) {
                idle.state.center_x = stretchAmplitude*sin(2*PI*period*steps);
                idle.state.center_y = stretchAmplitude*sin(2*PI*period*steps); 
                idle.state.center_z = 0;
            } else if(period > 0.5 && period <= 1) {
                idle.state.center_x = stretchAmplitude*sin(2*PI*(period-1/steps)*steps);
                idle.state.center_y = -stretchAmplitude*sin(2*PI*(period-1/steps)*steps);
                idle.state.center_z = 0;
            }
            break;
        case 3:    // Plus pattern
            steps = 2;
            stretchAmplitude = 35;
            if(period > 0 && period <= 0.5) {
                idle.state.center_x = 0;
                idle.state.center_y = stretchAmplitude*sin(2*PI*period*steps); 
                idle.state.center_z = 0;
            } else if(period > 0.5 && period <= 1) {
                idle.state.center_x = stretchAmplitude*sin(2*PI*(period-1/steps)*steps);
                idle.state.center_y = 0; 
                idle.state.center_z = 0;
            }
            break;
        case 4:     // Breath pattern
            stretchAmplitude = 10;
            idle.state.center_x = 0;
            idle.state.center_y = 0; 
            idle.state.center_z = stretchAmplitude*sin(2*PI*period)*sqrt(period);
            break;
        default:    // Stand still
            idle.state.center_x = 0;
            idle.state.center_y = 0; 
            idle.state.center_z = 0;
    } 
    // Set outputs to stateition the legs to the default stateition
    idle.state.x[LEG1_ID] = DEFAULT_X;
    idle.state.y[LEG1_ID] = DEFAULT_Y;
    idle.state.z[LEG1_ID] = DEFAULT_Z;
    idle.state.x[LEG2_ID] = -DEFAULT_X;
    idle.state.y[LEG2_ID] = DEFAULT_Y;
    idle.state.z[LEG2_ID] = DEFAULT_Z;
    idle.state.x[LEG3_ID] = -DEFAULT_X;
    idle.state.y[LEG3_ID] = -DEFAULT_Y;
    idle.state.z[LEG3_ID] = DEFAULT_Z;
    idle.state.x[LEG4_ID] = DEFAULT_X;
    idle.state.y[LEG4_ID] = -DEFAULT_Y;
    idle.state.z[LEG4_ID] = DEFAULT_Z;
    
    idle.flag = true;    // always true
    calculateAnglesFromState(idle.angles, idle.state);
    
    Serial.print("routine: ");
    Serial.println(routine);
}
