include<colors.scad>;
include<parameters.scad>;
include<for_diagrams.scad>;
use<single_leg.scad>;



// Positions of the tips of the legs.
// leg 1
x1 = 90+0*$t;
y1 = 90-0*$t;
z1 = 90+0*$t;
// leg 2
x2 = -75-0*$t;
y2 = 75+0*$t;
z2 = 90+0*$t;
// leg 3
x3 = -75-0*$t;
y3 = -75-0*$t;
z3 = 90+0*$t;
// leg 4
x4 = 90+0*$t;
y4 = -90-0*$t;
z4 = 90-0*$t;

four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4);



module four_legs(x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4, center_x=0,center_y=0,center_z=0) {
   
    x1_offset = x1-sqrt(center_offset*center_offset/2)-center_x;
    y1_offset = y1-sqrt(center_offset*center_offset/2)-center_y;
    z1_offset = z1+center_z;

    x2_offset = x2+sqrt(center_offset*center_offset/2)-center_x;
    y2_offset = y2-sqrt(center_offset*center_offset/2)-center_y;
    z2_offset = z2+center_z;

    x3_offset = x3+sqrt(center_offset*center_offset/2)-center_x;
    y3_offset = y3+sqrt(center_offset*center_offset/2)-center_y;
    z3_offset = z3+center_z;

    x4_offset = x4-sqrt(center_offset*center_offset/2)-center_x;
    y4_offset = y4+sqrt(center_offset*center_offset/2)-center_y;
    z4_offset = z4+center_z;

    x_leg1 = cal_x_prime(x1_offset,y1_offset,45);
    y_leg1 = cal_y_prime(x1_offset,y1_offset,45);
    z_leg1 = z1_offset;

    x_leg2 = cal_x_prime(x2_offset,y2_offset,135);
    y_leg2 = cal_y_prime(x2_offset,y2_offset,135);
    z_leg2 = z2_offset;

    x_leg3 = cal_x_prime(x3_offset,y3_offset,225);
    y_leg3 = cal_y_prime(x3_offset,y3_offset,225);
    z_leg3 = z3_offset;

    x_leg4 = cal_x_prime(x4_offset,y4_offset,315);
    y_leg4 = cal_y_prime(x4_offset,y4_offset,315);
    z_leg4 = z4_offset;

    u_leg1 = sqrt(x_leg1*x_leg1 + y_leg1*y_leg1);
    n_leg1 = sqrt((u_leg1-L1)*(u_leg1-L1) + z_leg1*z_leg1);
    a1_leg1 = acos((z_leg1*z_leg1+n_leg1*n_leg1-(u_leg1-L1)*(u_leg1-L1)) / (2*z_leg1*n_leg1));
    a2_leg1 = acos((n_leg1*n_leg1+L2*L2-L3*L3) / (2*n_leg1*L2));
    a3_leg1 = acos((L2*L2+L3*L3-n_leg1*n_leg1) / (2*L2*L3));

    u_leg2 = sqrt(x_leg2*x_leg2 + y_leg2*y_leg2);
    n_leg2 = sqrt((u_leg2-L1)*(u_leg2-L1) + z_leg2*z_leg2);
    a1_leg2 = acos((z_leg2*z_leg2+n_leg2*n_leg2-(u_leg2-L1)*(u_leg2-L1)) / (2*z_leg2*n_leg2));
    a2_leg2 = acos((n_leg2*n_leg2+L2*L2-L3*L3) / (2*n_leg2*L2));
    a3_leg2 = acos((L2*L2+L3*L3-n_leg2*n_leg2) / (2*L2*L3));

    u_leg3 = sqrt(x_leg3*x_leg3 + y_leg3*y_leg3);
    n_leg3 = sqrt((u_leg3-L1)*(u_leg3-L1) + z_leg3*z_leg3);
    a1_leg3 = acos((z_leg3*z_leg3+n_leg3*n_leg3-(u_leg3-L1)*(u_leg3-L1)) / (2*z_leg3*n_leg3));
    a2_leg3 = acos((n_leg3*n_leg3+L2*L2-L3*L3) / (2*n_leg3*L2));
    a3_leg3 = acos((L2*L2+L3*L3-n_leg3*n_leg3) / (2*L2*L3));

    u_leg4 = sqrt(x_leg4*x_leg4 + y_leg4*y_leg4);
    n_leg4 = sqrt((u_leg4-L1)*(u_leg4-L1) + z_leg4*z_leg4);
    a1_leg4 = acos((z_leg4*z_leg4+n_leg4*n_leg4-(u_leg4-L1)*(u_leg4-L1)) / (2*z_leg4*n_leg4));
    a2_leg4 = acos((n_leg4*n_leg4+L2*L2-L3*L3) / (2*n_leg4*L2));
    a3_leg4 = acos((L2*L2+L3*L3-n_leg4*n_leg4) / (2*L2*L3));

    a11 = atan(y_leg1/x_leg1);
    a12 = a1_leg1 + a2_leg1 - 90;
    a13 = 180 - a3_leg1;

    a21 = atan(y_leg2/x_leg2);
    a22 = a1_leg2 + a2_leg2 - 90;
    a23 = 180 - a3_leg2;

    a31 = atan(y_leg3/x_leg3);
    a32 = a1_leg3 + a2_leg3 - 90;
    a33 = 180 - a3_leg3;

    a41 = atan(y_leg4/x_leg4);
    a42 = a1_leg4 + a2_leg4 - 90;
    a43 = 180 - a3_leg4;

    translate([center_x,center_y,center_z]) {
        rotate([0,0,45]) translate([center_offset,0,0]) 
            single_leg([a11,-a12,a13], lime, lime, lime);          // leg 1
        rotate([0,0,135]) translate([center_offset,0,0]) 
            single_leg([a21,-a22,a23], blue, blue, blue);          // leg 2
        rotate([0,0,225]) translate([center_offset,0,0]) 
            single_leg([a31,-a32,a33], purple, purple, purple);    // leg 3
        rotate([0,0,315]) translate([center_offset,0,0]) 
            single_leg([a41,-a42,a43], orange, orange, orange);    // leg 4
    }
}

// Planar rotation (x -> x')
function cal_x_prime(x,y,angle) = x*cos(angle) + y*sin(angle);
function cal_y_prime(x,y,angle) = -x*sin(angle) + y*cos(angle);