include<colors.scad>;
include<parameters.scad>;
include<for_diagrams.scad>;



x = 60+60*$t;
y = 60-30*$t;
z = 60+20*$t;

u = sqrt(x*x + y*y);
n = sqrt((u-L1)*(u-L1) + z*z);
a1 = acos((z*z+n*n-(u-L1)*(u-L1)) / (2*z*n));
a2 = acos((n*n+L2*L2-L3*L3) / (2*n*L2));
a3 = acos((L2*L2+L3*L3-n*n) / (2*L2*L3));

alpha = atan(y/x);
beta = a1 + a2 - 90;
gamma = 180 - a3;

distance_x(red);
distance_y(green);
distance_z(blue);
distance_u();
distance_n(grey);
single_leg([alpha,-beta,gamma], brown, purple, orange);



module single_leg(angles, color1, color2, color3) {
    rotate([0,0,angles[0]]) {
        leg_part(L1, color1, "L", "1");                      // leg part 1
        translate([L1,0,0]) rotate([0,angles[1],0]) {
            leg_part(L2, color2, "L", "2");                  // leg part 2
            translate([L2,0,0]) rotate([0,angles[2],0]) {
                leg_part(L3, color3, "L", "3");              // leg part 3
            }
        }
    }
}

module leg_part(length, color, label1, label2) {
    translate([length/2, 0, 0]) color(color) 
    if (SHOW_LABEL) 
        d_length_t2(length, label1, label2); 
    else 
        cube([length, 1, 1], true);
}

module distance_x(color) {
    translate([(x)/2,0,-z]) rotate([0,0,0]) color(color)
    d_length_t1(x,"X");
}
module distance_y(color) {
    translate([0,y/2,-z]) rotate([0,0,90]) color(color)
    d_length_t1(y,"Y");
}
module distance_z(color){
    translate([0,0,-z/2]) rotate([0,-90,90]) color(color)
    d_length_t1(z,"Z");
}
module distance_u(color){
    rotate([0,0,alpha]) translate([(u)/2,0,-z]) color(color)
    d_length_t1(u,"u");
}
module distance_n(color){
    rotate([0,0,alpha]) translate([L1,0,0]) rotate([0,90-a1,0]) translate([n/2,0,0]) rotate([90,0,0]) color(color)
    d_length_t1(n,"n");
}

