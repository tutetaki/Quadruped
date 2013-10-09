use<four_legs.scad>;


//idle1();
//idle2();
idle3();
//idle4();


/**
 * Idle routine 1. The center of the robot draw a circle while the legs stay put.
 */
module idle1() {
    STRETCH_AMPLITUDE = 20;
    rotation = 1;

    i = STRETCH_AMPLITUDE*cos(360*$t);
	echo("cos(360*$t): ", cos(360*$t));
    j = rotation*STRETCH_AMPLITUDE*sin(360*$t);
    k = -0*$t;
    x1 = 90;
    y1 = 90;
    z1 = 90;

    x2 = -90;
    y2 = 90;
    z2 = 90;

    x3 = -90;
    y3 = -90;
    z3 = 90;

    x4 = 90;
    y4 = -90;
    z4 = 90;

    translate([i,j,k]) cube([15,15,2], true);
    four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
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
                x1 = 90,y1 = 90,z1 = 90,
                x2 = -90,y2 = 90,z2 = 90,
                x3 = -90,y3 = -90,z3 = 90,
                x4 = 90,y4 = -90,z4 = 90) {
            translate([i,j,k]) cube([15,15,2], true);
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
        }
    } else if($t > 0.5 && $t <= 1) {
        assign (i = STRETCH_AMPLITUDE*sin(360*($t-1/STEPS)*STEPS), 
                j = -STRETCH_AMPLITUDE*sin(360*($t-1/STEPS)*STEPS),
                k = 0,
                x1 = 90,y1 = 90,z1 = 90,
                x2 = -90,y2 = 90,z2 = 90,
                x3 = -90,y3 = -90,z3 = 90,
                x4 = 90,y4 = -90,z4 = 90) {
            translate([i,j,k]) cube([15,15,2], true);
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
                x1 = 90,y1 = 90,z1 = 90,
                x2 = -90,y2 = 90,z2 = 90,
                x3 = -90,y3 = -90,z3 = 90,
                x4 = 90,y4 = -90,z4 = 90) {
            translate([i,j,k]) cube([15,15,2], true);
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
        }
    } else if($t > 0.5 && $t <= 1) {
        assign (i = STRETCH_AMPLITUDE*sin(360*($t-1/STEPS)*STEPS), 
                j = 0,
                k = 0,
                x1 = 90,y1 = 90,z1 = 90,
                x2 = -90,y2 = 90,z2 = 90,
                x3 = -90,y3 = -90,z3 = 90,
                x4 = 90,y4 = -90,z4 = 90) {
            translate([i,j,k]) cube([15,15,2], true);
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
        }
    }
}


/**
 * Idle routine 4. The center of the robot goes up then down and back.
 */
module idle4() {
    STRETCH_AMPLITUDE = 5;
    i = 0;
    j = 0;
    k = STRETCH_AMPLITUDE*sin(360*$t)*sqrt($t);
	echo("$t: ", $t);
	echo("cos: ", cos(360*$t));
    x1 = 90;
    y1 = 90;
    z1 = 90;

    x2 = -90;
    y2 = 90;
    z2 = 90;

    x3 = -90;
    y3 = -90;
    z3 = 90;

    x4 = 90;
    y4 = -90;
    z4 = 90;

    translate([i,j,k]) cube([15,15,2], true);
    four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
}