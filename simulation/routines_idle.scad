use<four_legs.scad>;

X_DEFAULT = 95;
Y_DEFAULT = 95;
Z_DEFAULT = 80;

//idle1();
//idle2();
//idle3();
//idle4();
idle5();


/**
 * Idle routine 1. The center of the robot draw a circle while the legs stay put.
 */
module idle1() {
    STRETCH_AMPLITUDE = 50;
    STEPS = 2;

    if($t > 0 && $t <= 0.5) {
        assign (i = STRETCH_AMPLITUDE*$t*cos(360*$t*STEPS), 
                j = STRETCH_AMPLITUDE*$t*sin(360*$t*STEPS), 
                k = 0,
                x1 = X_DEFAULT,y1 = Y_DEFAULT,z1 = Z_DEFAULT,
                x2 = -X_DEFAULT,y2 = Y_DEFAULT,z2 = Z_DEFAULT,
                x3 = -X_DEFAULT,y3 = -Y_DEFAULT,z3 = Z_DEFAULT,
                x4 = X_DEFAULT,y4 = -Y_DEFAULT,z4 = Z_DEFAULT) {
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
        }
    } else if($t > 0.5 && $t <= 1) {
        assign (i = STRETCH_AMPLITUDE*(1-$t)*cos(360*($t-1/STEPS)*STEPS), 
                j = STRETCH_AMPLITUDE*(1-$t)*sin(360*($t-1/STEPS)*STEPS),
                k = 0,
                x1 = X_DEFAULT,y1 = Y_DEFAULT,z1 = Z_DEFAULT,
                x2 = -X_DEFAULT,y2 = Y_DEFAULT,z2 = Z_DEFAULT,
                x3 = -X_DEFAULT,y3 = -Y_DEFAULT,z3 = Z_DEFAULT,
                x4 = X_DEFAULT,y4 = -Y_DEFAULT,z4 = Z_DEFAULT) {
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
        }
    }
}

/**
 * Idle routine 2. The center of the robot draw a x-cross while the legs stay put.
 */
module idle2() {
    STRETCH_AMPLITUDE = 30;
    STEPS = 2;

    if($t > 0 && $t <= 0.5) {
        assign (i = STRETCH_AMPLITUDE*sin(360*$t*STEPS),
                j = STRETCH_AMPLITUDE*sin(360*$t*STEPS),
                k = 0,
                x1 = X_DEFAULT,y1 = Y_DEFAULT,z1 = Z_DEFAULT,
                x2 = -X_DEFAULT,y2 = Y_DEFAULT,z2 = Z_DEFAULT,
                x3 = -X_DEFAULT,y3 = -Y_DEFAULT,z3 = Z_DEFAULT,
                x4 = X_DEFAULT,y4 = -Y_DEFAULT,z4 = Z_DEFAULT) {
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
        }
    } else if($t > 0.5 && $t <= 1) {
        assign (i = STRETCH_AMPLITUDE*sin(360*($t-1/STEPS)*STEPS), 
                j = -STRETCH_AMPLITUDE*sin(360*($t-1/STEPS)*STEPS),
                k = 0,
                x1 = X_DEFAULT,y1 = Y_DEFAULT,z1 = Z_DEFAULT,
                x2 = -X_DEFAULT,y2 = Y_DEFAULT,z2 = Z_DEFAULT,
                x3 = -X_DEFAULT,y3 = -Y_DEFAULT,z3 = Z_DEFAULT,
                x4 = X_DEFAULT,y4 = -Y_DEFAULT,z4 = Z_DEFAULT) {
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
        }
    }
}

/**
 * Idle routine 3. The center of the robot draw a +-cross while the legs stay put.
 */
module idle3() {
    STRETCH_AMPLITUDE = 40;
    STEPS = 2;

    if($t > 0 && $t <= 0.5) {
        assign (i = 0, 
                j = STRETCH_AMPLITUDE*sin(360*$t*STEPS),
                k = 0,
                x1 = X_DEFAULT,y1 = Y_DEFAULT,z1 = Z_DEFAULT,
                x2 = -X_DEFAULT,y2 = Y_DEFAULT,z2 = Z_DEFAULT,
                x3 = -X_DEFAULT,y3 = -Y_DEFAULT,z3 = Z_DEFAULT,
                x4 = X_DEFAULT,y4 = -Y_DEFAULT,z4 = Z_DEFAULT) {
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
        }
    } else if($t > 0.5 && $t <= 1) {
        assign (i = STRETCH_AMPLITUDE*sin(360*($t-1/STEPS)*STEPS), 
                j = 0,
                k = 0,
                x1 = X_DEFAULT,y1 = Y_DEFAULT,z1 = Z_DEFAULT,
                x2 = -X_DEFAULT,y2 = Y_DEFAULT,z2 = Z_DEFAULT,
                x3 = -X_DEFAULT,y3 = -Y_DEFAULT,z3 = Z_DEFAULT,
                x4 = X_DEFAULT,y4 = -Y_DEFAULT,z4 = Z_DEFAULT) {
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
        }
    }
}


/**
 * Idle routine 4. The center of the robot goes up then down and back.
 */
module idle4() {
    STRETCH_AMPLITUDE = 10;
    i = 0;
    j = 0;
    k = STRETCH_AMPLITUDE*sin(360*$t)*sqrt($t);
	echo("$t: ", $t);
	echo("cos: ", cos(360*$t));
    x1 = X_DEFAULT;
    y1 = Y_DEFAULT;
    z1 = Z_DEFAULT;

    x2 = -X_DEFAULT;
    y2 = Y_DEFAULT;
    z2 = Z_DEFAULT;

    x3 = -X_DEFAULT;
    y3 = -Y_DEFAULT;
    z3 = Z_DEFAULT;

    x4 = X_DEFAULT;
    y4 = -Y_DEFAULT;
    z4 = Z_DEFAULT;

    four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
}

/**
 * Idle routine 5. The center of the robot turns in one direction then in the oposite and finally return to zero.
 */
module idle5() {
    STRETCH_AMPLITUDE = 40;
    STEPS = 2;

    if($t > 0 && $t <= 0.5) {
        assign (theta = STRETCH_AMPLITUDE*sin(360*$t*STEPS),
                x1 = X_DEFAULT,y1 = Y_DEFAULT,z1 = Z_DEFAULT,
                x2 = -X_DEFAULT,y2 = Y_DEFAULT,z2 = Z_DEFAULT,
                x3 = -X_DEFAULT,y3 = -Y_DEFAULT,z3 = Z_DEFAULT,
                x4 = X_DEFAULT,y4 = -Y_DEFAULT,z4 = Z_DEFAULT) {
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, 0,0,0, theta,0);
        }
    } else if($t > 0.5 && $t <= 1) {
        assign (theta = STRETCH_AMPLITUDE*sin(360*($t-1/STEPS)*STEPS), 
                x1 = X_DEFAULT,y1 = Y_DEFAULT,z1 = Z_DEFAULT,
                x2 = -X_DEFAULT,y2 = Y_DEFAULT,z2 = Z_DEFAULT,
                x3 = -X_DEFAULT,y3 = -Y_DEFAULT,z3 = Z_DEFAULT,
                x4 = X_DEFAULT,y4 = -Y_DEFAULT,z4 = Z_DEFAULT) {
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, 0,0,0, theta,0);
        }
    }
}