/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

void motors_command(Behaviour *b) {
    int k = 0;
    for(int i=0; i < NBR_LEGS; i++) {
        for(int j=0; j < NBR_JOINTS; j++) {
            Servos[k].write(b -> angles[i][j]);
            k++;
        }
    }
}
