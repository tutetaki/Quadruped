/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

Behaviour idle;

/*
 * Idle Behaviour (default, flag always TRUE): 
 *    Stand still. This is what the robot does when no other behaviour request the control.
 *    - Default idle routine: the robot stands perfectly still.
 *    - Idle routine 1: The center of the robot draw a circle while the legs stay put.
 *    - Idle routine 2: The center of the robot draw a x-cross while the legs stay put.
 *    - Idle routine 3: The center of the robot draw a +-cross while the legs stay put.
 *    - Idle routine 4: The center of the robot goes up then down and back.
 * TODO: Idle routine 5: The center of the robot turns 90° in one direction then 180° in the opposite and back to zero while the legs stay put.
 */
void idleTask(int routine) {
    int stretchAmplitude;
    
    switch (routine) {
        case 1:    // Circle pattern, change the sign to change rotation direction
            stretchAmplitude = 30;
            idle.pos.center_x = stretchAmplitude*cos(2*PI*period);
            idle.pos.center_y = 1 * stretchAmplitude*sin(2*PI*period);
            idle.pos.center_z = 0;
            break;
        case 2:    // Cross pattern
            stretchAmplitude = 30;
            if(period > 0 && period <= 0.5) {
                idle.pos.center_x = stretchAmplitude*sin(2*PI*period*2);
                idle.pos.center_y = stretchAmplitude*sin(2*PI*period*2); 
                idle.pos.center_z = 0;
            } else if(period > 0.5 && period <= 1) {
                idle.pos.center_x = stretchAmplitude*sin(2*PI*period*2);
                idle.pos.center_y = -stretchAmplitude*sin(2*PI*period*2); 
                idle.pos.center_z = 0;
            }
            break;
        case 3:    // Plus pattern
            stretchAmplitude = 30;
            if(period > 0 && period <= 0.5) {
                idle.pos.center_x = 0;
                idle.pos.center_y = stretchAmplitude*sin(2*PI*period*2); 
                idle.pos.center_z = 0;
            } else if(period > 0.5 && period <= 1) {
                idle.pos.center_x = stretchAmplitude*sin(2*PI*period*2);
                idle.pos.center_y = 0; 
                idle.pos.center_z = 0;
            }
            break;
        case 4:     // Breath pattern
            stretchAmplitude = 5;
            idle.pos.center_x = 0;
            idle.pos.center_y = 0; 
            idle.pos.center_z = stretchAmplitude*sin(2*PI*period)*sqrt(period);;
            break;
        default:    // Stand still
            idle.pos.center_x = 0;
            idle.pos.center_y = 0; 
            idle.pos.center_z = 0;
    } 
    // Set outputs to position the legs to the default position
    idle.pos.x[LEG1_ID] = DEFAULT_X;
    idle.pos.y[LEG1_ID] = DEFAULT_Y;
    idle.pos.z[LEG1_ID] = DEFAULT_Z;
    idle.pos.x[LEG2_ID] = -DEFAULT_X;
    idle.pos.y[LEG2_ID] = DEFAULT_Y;
    idle.pos.z[LEG2_ID] = DEFAULT_Z;
    idle.pos.x[LEG3_ID] = -DEFAULT_X;
    idle.pos.y[LEG3_ID] = -DEFAULT_Y;
    idle.pos.z[LEG3_ID] = DEFAULT_Z;
    idle.pos.x[LEG4_ID] = DEFAULT_X;
    idle.pos.y[LEG4_ID] = -DEFAULT_Y;
    idle.pos.z[LEG4_ID] = DEFAULT_Z;
    
    calculateAnglesFromPositions(idle.angles, idle.pos);
    idle.flag = true;    // always true
}
