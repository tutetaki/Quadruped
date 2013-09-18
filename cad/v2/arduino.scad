/* Arduino Board - 23/07/2011 
-------------------------------------------------------- */
M3 = 3/2;

ardUno_x = 68.6;
ardUno_y = 53.3;
ardUno_z = 2;




//ardUno();
module ardUno(){
  color([80/255,80/255,200/255]){
    translate([-ardUno_x/2, -ardUno_y/2, -ardUno_z/2])
      difference(){
        cube([ardUno_x, ardUno_y, ardUno_z]);
        translate([14, 2.5, 0]) cylinder(r=M3, h=20, center=true);  
        translate([14+1.3+50.8, 2.5+5.1, 0]) cylinder(r=M3, h=10, center=true);
        translate([14+1.3+50.8, 2.5+5.1+27.9, 0]) cylinder(r=M3, h=10, center=true);
        translate([14+1.3, 2.5+5.1+27.9+15.2, 0]) cylinder(r=M3, h=10, center=true);
      }
  }
}