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
void idle_behaviour(int routine) {
    int stretch_amplitude;
    switch (routine) {
        case 1:    // TODO: test routine
            stretch_amplitude = 10;
            idle.pos.center_x = stretch_amplitude*cos(period);
            idle.pos.center_y = 1*stretch_amplitude*sin(period);    // change the sign to change rotation direction
            idle.pos.center_z = 0;
            break;
        case 2:    // TODO: test routine
            stretch_amplitude = 30;
            if(period > 0 && period <= 0.5) {
                idle.pos.center_x = stretch_amplitude*sin(period*2);
                idle.pos.center_y = stretch_amplitude*sin(period*2); 
                idle.pos.center_z = 0;
            } else if(period > 0.5 && period <= 1) {
                idle.pos.center_x = stretch_amplitude*sin(period*2);
                idle.pos.center_y = -stretch_amplitude*sin(period*2); 
                idle.pos.center_z = 0;
            }
            break;
        case 3:    // TODO: test routine
            stretch_amplitude = 30;
            if(period > 0 && period <= 0.5) {
                idle.pos.center_x = 0;
                idle.pos.center_y = stretch_amplitude*sin(period*2); 
                idle.pos.center_z = 0;
            } else if(period > 0.5 && period <= 1) {
                idle.pos.center_x = stretch_amplitude*sin(period*2);
                idle.pos.center_y = 0; 
                idle.pos.center_z = 0;
            }
            break;
        case 4:    // TODO: test routine
            stretch_amplitude = 5;
            idle.pos.center_x = 0;
            idle.pos.center_y = 0; 
            idle.pos.center_z = stretch_amplitude*sin(period*2)*sqrt(period);;
            break;
        default:    // TODO: test routine
            idle.pos.center_x = 0;
            idle.pos.center_y = 0; 
            idle.pos.center_z = 0;
    } 
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
    
    get_angles_from_positions(idle.angles, idle.pos);
    idle.flag = true;    // always true
}
