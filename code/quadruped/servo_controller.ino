/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

void commandServos(Behaviour *b) {
    int k = 0;
    for(int i=0; i < NBR_LEGS; i++) {
        for(int j=0; j < NBR_JOINTS; j++) {
            servos[k].write(b -> angles[i][j]);
            k++;
        }
    }
}

int s[4][2] = {{1,1}, {-1,1}, {-1,-1}, {1,-1}};
void calculateAnglesFromPositions(int angles[][NBR_JOINTS], Positions positions) {
    for(int i=0; i < NBR_LEGS; i++) {
        legs[i].x_offset = positions.x[i] - s[i][0]*sqrt(CENTER_OFFSET*CENTER_OFFSET/2) - positions.center_x;
        legs[i].y_offset = positions.y[i] - s[i][1]*sqrt(CENTER_OFFSET*CENTER_OFFSET/2) - positions.center_y;
        legs[i].z_offset = positions.z[i] + positions.center_z;

        legs[i].x = calculateXPrime(legs[i].x_offset, legs[i].y_offset, HALF_PI/2 + HALF_PI*i);
        legs[i].y = calculateYPrime(legs[i].x_offset, legs[i].y_offset, HALF_PI/2 + HALF_PI*i);
        legs[i].z = legs[i].z_offset;

        legs[i].u = sqrt(legs[i].x*legs[i].x + legs[i].y*legs[i].y);
        legs[i].n = sqrt((legs[i].u-L1)*(legs[i].u-L1) + legs[i].z*legs[i].z);
        legs[i].a[0] = acos((legs[i].z*legs[i].z+legs[i].n*legs[i].n-(legs[i].u-L1)*(legs[i].u-L1)) / (2*legs[i].z*legs[i].n));
        legs[i].a[1] = acos((legs[i].n*legs[i].n+L2*L2-L3*L3) / (2*legs[i].n*L2));
        legs[i].a[2] = acos((L2*L2+L3*L3-legs[i].n*legs[i].n) / (2*L2*L3));

        angles[i][JOINT1_ID] = JOINT1_OFFSET + ( atan(legs[i].y/legs[i].x) ) * RAD_TO_DEG;
        angles[i][JOINT2_ID] = JOINT2_OFFSET + ( legs[i].a[0] + legs[i].a[1] - HALF_PI ) * RAD_TO_DEG;
        angles[i][JOINT3_ID] = JOINT3_OFFSET - ( PI - legs[i].a[2] ) * RAD_TO_DEG;
    }
}

// Planar rotation (x -> x')
int calculateXPrime(int x, int y, float angle) {
    return x*cos(angle) + y*sin(angle);
}
// Planar rotation (y -> y')
int calculateYPrime(int x, int y, float angle) {
    return -x*sin(angle) + y*cos(angle);
}
