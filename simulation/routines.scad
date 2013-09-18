use<four_legs.scad>;



idle1();
//idle2();
//idle3();
//idle4();
//walk(0, 70);



/**
 * Idle routine 1. The center of the robot draw a circle while the legs stay put.
 */
module idle1() {
    STRETCH_AMPLITUDE = 10;
    rotation = 1;

    i = STRETCH_AMPLITUDE*cos(360*$t);
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

    if($t > 0 && $t <= 0.5) {
        assign (i = STRETCH_AMPLITUDE*sin(360*$t*2), 
                j = STRETCH_AMPLITUDE*sin(360*$t*2),
                k = 0,
                x1 = 90,y1 = 90,z1 = 90,
                x2 = -90,y2 = 90,z2 = 90,
                x3 = -90,y3 = -90,z3 = 90,
                x4 = 90,y4 = -90,z4 = 90) {
            translate([i,j,k]) cube([15,15,2], true);
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
        }
    } else if($t > 0.5 && $t <= 1) {
        assign (i = STRETCH_AMPLITUDE*sin(360*$t*2), 
                j = -STRETCH_AMPLITUDE*sin(360*$t*2),
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
    if($t > 0 && $t <= 0.5) {
        assign (i = 0, 
                j = STRETCH_AMPLITUDE*sin(360*$t*2),
                k = 0,
                x1 = 90,y1 = 90,z1 = 90,
                x2 = -90,y2 = 90,z2 = 90,
                x3 = -90,y3 = -90,z3 = 90,
                x4 = 90,y4 = -90,z4 = 90) {
            translate([i,j,k]) cube([15,15,2], true);
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
        }
    } else if($t > 0.5 && $t <= 1) {
        assign (i = STRETCH_AMPLITUDE*sin(360*$t*2), 
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
    k = STRETCH_AMPLITUDE*sin(360*$t*2)*sqrt($t);
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
 * Walking routine. Thi is a sinusoidal gait which takes a direction and a distance as inputs. 
 * - If the distance is below the WALK_THRESHOLD only the body moves, no walking.
 * - One leg at a time is up.
 * - The robot's center of mass should be as close as possible to center of the triangle formed by the three other legs.
 * - The lifted leg sequence depends on the orientation:
 *     - <315;45>  -> 1,2,3,4
 *     - <45;135>  -> 2,3,4,1
 *     - <135;225> -> 3,4,1,2
 *     - <225;315> -> 4,1,2,3
 */
module walk(direction, distance) {
    WALK_THRESHOLD = 50;
    LEG_Z_LIFT = 15;
    GAIT_AMPLITUDE = 40;
    STEPS = 4;

    if(distance <= WALK_THRESHOLD) {
        assign (i = distance*cos(direction)*$t, 
                j = distance*sin(direction)*$t,
                k = 0,
                x1 = 90,y1 = 90,z1 = 90,
                x2 = -90,y2 = 90,z2 = 90,
                x3 = -90,y3 = -90,z3 = 90,
                x4 = 90,y4 = -90,z4 = 90) {
            translate([i,j,k]) cube([15,15,2], true);
            four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
        }
    }
    else {
        assign (i = distance*cos(direction)*$t+cal_x($t, GAIT_AMPLITUDE*sin(360*$t+180), direction), 
                j = distance*sin(direction)*$t+cal_y($t, GAIT_AMPLITUDE*sin(360*$t+180), direction),
                k = 0) {
            translate([i,j,k]) cube([15,15,2], true);
            if($t > 0 && $t <= 0.25) {
                assign (
                        x1 = 90+distance*cos(direction)*$t*STEPS,y1 = 90+distance*sin(direction)*$t*STEPS,z1 = 90-LEG_Z_LIFT,
                        x2 = -90,y2 = 90,z2 = 90,
                        x3 = -90,y3 = -90,z3 = 90,
                        x4 = 90,y4 = -90,z4 = 90) {
                    four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
                }
            } else if($t > 0.25 && $t <= 0.5) {
                assign (
                        x1 = 90+distance*cos(direction),y1 = 90+distance*sin(direction),z1 = 90,
                        x2 = -90+distance*cos(direction)*$t*STEPS/2,y2 = 90+distance*sin(direction)*$t*STEPS/2,z2 = 90-LEG_Z_LIFT,
                        x3 = -90,y3 = -90,z3 = 90,
                        x4 = 90,y4 = -90,z4 = 90) {
                    four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
                }
            } else if($t > 0.5 && $t <= 0.75) {
                assign (
                        x1 = 90+distance*cos(direction),y1 = 90+distance*sin(direction),z1 = 90,
                        x2 = -90+distance*cos(direction),y2 = 90+distance*sin(direction),z2 = 90,
                        x3 = -90+distance*cos(direction)*$t*STEPS/3,y3 = -90+distance*sin(direction)*$t*STEPS/3,z3 = 90-LEG_Z_LIFT,
                        x4 = 90,y4 = -90,z4 = 90) {
                    four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
                }
            } else if($t > 0.75 && $t <= 1) {
                assign (
                        x1 = 90+distance*cos(direction),y1 = 90+distance*sin(direction),z1 = 90,
                        x2 = -90+distance*cos(direction),y2 = 90+distance*sin(direction),z2 = 90,
                        x3 = -90+distance*cos(direction),y3 = -90+distance*sin(direction),z3 = 90,
                        x4 = 90+distance*cos(direction)*$t*STEPS/4,y4 = -90+distance*sin(direction)*$t*STEPS/4,z4 = 90-LEG_Z_LIFT) {
                    four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, i,j,k);
                }
            }
        }
    }
}

// Planar rotation (x' -> x)
function cal_x(x_prime,y_prime,angle) = x_prime*cos(angle) - y_prime*sin(angle);
function cal_y(x_prime,y_prime,angle) = x_prime*sin(angle) + y_prime*cos(angle);