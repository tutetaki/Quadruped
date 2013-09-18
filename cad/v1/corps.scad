/* Quadrup�de - 15/07/2011 
-------------------------------------------------------- */
include<parametres.scad>;
include<arduino.scad>;
include<plaques.scad>;
include<servo.scad>;


/*  Corps 
================================ */
//corps();
module corps(){
 //%translate([0,0,29]) ardUno();
 //translate([0,0,25]) plaque1();
  plaque2();
  
  for(i = [1, 3, 5, 7]){
    rotate([0,0,i*pi/4]) translate([0,-AH/3,-(hauteur+s_z2/2-s_z1/2)+c_z/2+e]) servoCaout();
  }

}


/*  Cuisse 
================================ */
//cuisse(0,30);
module cuisse(theta, phi){
  support2(theta);
  rotate([0,0,theta]){
    translate([0,-2*d_supServ,0]){ 
      rotate([-phi,0,0]){ 
        rotate([0,0,180]) rotate([0,90,0]) servo();
        translate([0,-a_y-s_y2/2-s_y1/2,0]) rotate([0,90,0]) servo();
      }
    }
  }
}


/*  Jambe (/!\ eq Arduino)
================================ */
//jambe(0,140,90);
module jambe(x, y, z){
//  color([1,0,0]) translate([25,0,0]) cube([50,1,1], true);
//  color([0,1,0]) translate([0,100,0]) cube([1,200,1], true);
//  color([0,0,1]) translate([0,0,25]) cube([1,1,50], true);
// % translate([0,0,-z-2]) cube([x+2,y+2,1]);
	  
  u = sqrt(x*x+y*y);

  i = y*L1/u;
  j = x*L1/u;
    theta = -atan(j/i);

  n = sqrt(z*z+(u-sqrt(i*i+j*j))*(u-sqrt(i*i+j*j)));
  alpha = acos((L2*L2+n*n-L3*L3)/(2*L2*n));
  beta = asin(z/n);
    phi = alpha-beta;
  
  gamma = acos((L2*L2+L3*L3-n*n)/(2*L2*L3));
    psi = 180-gamma;

  echo("theta : ",theta+90,  "         phi : ",phi+90,  "         psi : ",180-psi );

  translate([0,0,-(hauteur+s_z2/2-s_z1/2)+c_z/2+e]) rotate([0,0,180]){
    cuisse(theta, phi);
    rotate([0,0,theta]){
      translate([0,-2*d_supServ,0]){ 
        rotate([-phi,0,0]){
          translate([0,-a_y-s_y2/2-s_y1/2,0]) support3(psi);
        }
      }
    }
  }
}