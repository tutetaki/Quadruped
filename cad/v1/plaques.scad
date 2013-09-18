/* Quadrup�de - 15/07/2011 
-------------------------------------------------------- */
include<parametres.scad>;
include<arduino.scad>;
include<shapes.scad>;


/*  Plaque 1 
================================ */
//plaque1();
module plaque1(){
  difference(){
    union(){
      cube([DE,AH,e], true);
      cube([AH,DE,e], true);
      for(i = [1, 2, 3, 4]){ 
        rotate([0,0,i*90]) difference(){
            translate([(JC+AB)/2+AB,(JC+AB)/2+AB,0]) cube([JC+AB,JC+AB,e], true);
            translate([AH/2,AH/2,0]) cylinder(r=AH/2-AB, h=e+1, center=true, $fn=12);
        }
      }
    }

    for(i = [1, 2, 3, 4]){ 
      rotate([0,0,i*90]){
        translate([AH/5.5,0,0]) cube([3+m,3+m,5], true); 
      }
    }
    translate([-ardUno_x/2, -ardUno_y/2, -ardUno_z/2]){
      translate([14, 2.5, 0]) rotate([0,0,45]) cube([3+m,3+m,5], true);
      translate([14+1.3+50.8, 2.5+5.1, 0]) rotate([0,0,45]) cube([3+m,3+m,5], true);
      translate([14+1.3+50.8, 2.5+5.1+27.9, 0]) rotate([0,0,45]) cube([3+m,3+m,5], true);
      translate([14+1.3, 2.5+5.1+27.9+15.2, 0]) rotate([0,0,45]) cube([3+m,3+m,5], true);
    }
  }
}


/*  Plaque 2 
================================ */
//plaque2();
module plaque2(){
  difference(){
    union(){
      rotate([0,0,45]){
        cube([AI,AI,2*e], true);
        cube([LM,ON-LM,2*e], true);
        cube([ON-LM,LM,2*e], true);
        for(i = [1, 2, 3, 4]){ 
          rotate([0,0,i*90]) translate([ON/2-LM/2,0,0]) cylinder(r=LM/2, h=2*e, center=true, $fn=15); 

        }
      }
    }

    for(i = [1, 2, 3, 4]){ 
      rotate([0,0,i*90]){
        translate([AH/2,0,0]) cylinder(r=(AI-LM)/2, h=2*e+1, center=true, $fn=16); 
        translate([AH/5.5,0,0]) rotate([0,0,45]) cube([3+m,3+m,100], true); 
      }
      rotate([0,0,i*90+45]){ // trous de servo
        translate([0,s_y1/2-a_y-AH/3,0]) cube([s_x1+m,s_y1+m,s_z1],true);
        translate([0,-AH/3-s_y1/2+3.5,0]) cube([4+m,3+m,s_z1],true);
        translate([0,-AH/3+s_y1/2+a_y-1.5,0]) cube([3+m,3+m,100], true);
        translate([0,-AH/3-s_y1/2+1.5,0]) cube([3+m,3+m,100], true);
      }
    }
  }
}



