/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

void calculateAnglesFromState(int angles[], State state) {
    int s[4][2] = {{1,1}, {-1,1}, {-1,-1}, {1,-1}};
    for(int i=0; i < NBR_LEGS; i++) {
        legs[i].x_offset = state.x[i] - s[i][0]*sqrt(CENTER_OFFSET*CENTER_OFFSET/2) - state.center_x;
        legs[i].y_offset = state.y[i] - s[i][1]*sqrt(CENTER_OFFSET*CENTER_OFFSET/2) - state.center_y;
        legs[i].z_offset = state.z[i] + state.center_z;

        legs[i].x = calculateXPrime(legs[i].x_offset, legs[i].y_offset, HALF_PI/2 + HALF_PI*i);
        legs[i].y = calculateYPrime(legs[i].x_offset, legs[i].y_offset, HALF_PI/2 + HALF_PI*i);
        legs[i].z = legs[i].z_offset;

        legs[i].u = sqrt(legs[i].x*legs[i].x + legs[i].y*legs[i].y);
        legs[i].n = sqrt((legs[i].u-L1)*(legs[i].u-L1) + legs[i].z*legs[i].z);
        legs[i].a[0] = acos((legs[i].z*legs[i].z+legs[i].n*legs[i].n-(legs[i].u-L1)*(legs[i].u-L1)) / (2*legs[i].z*legs[i].n));
        legs[i].a[1] = acos((legs[i].n*legs[i].n+L2*L2-L3*L3) / (2*legs[i].n*L2));
        legs[i].a[2] = acos((L2*L2+L3*L3-legs[i].n*legs[i].n) / (2*L2*L3));

        angles[NBR_JOINTS*i] = ANGLE1_OFFSET + ( atan2(legs[i].y, legs[i].x) ) * RAD_TO_DEG;
        angles[NBR_JOINTS*i+1] = ANGLE2_OFFSET + ( legs[i].a[0] + legs[i].a[1] - HALF_PI ) * RAD_TO_DEG;
        angles[NBR_JOINTS*i+2] = ANGLE3_OFFSET - ( PI - legs[i].a[2] ) * RAD_TO_DEG;
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
