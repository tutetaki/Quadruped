/* Quadrupède - 15/07/2011 
-------------------------------------------------------- */
include<parametres.scad>;
include<arduino.scad>;
include<plaques.scad>;
include<servo.scad>;


/*  Corps 
================================ */
//corps();
module corps(){
  translate([0,0,29]) ardUno();
  translate([0,0,25]) plaque1();
  plaque2();
  
  for(i = [1, 3, 5, 7]){
    rotate([0,0,i*pi/4]) translate([0,-AH/3,-(hauteur+s_z2/2-s_z1/2)+c_z/2+e]) servoCaout();
  }

}


/*  Cuisse 
================================ */
//cuisse(0,0);
module cuisse(theta, phi){
  support2(theta);
  rotate([0,0,-theta]){
    translate([0,2*d_supServ,0]){ 
      rotate([90-phi,0,180]){ 
        rotate([0,0,180]) rotate([0,90,0]) servo();
        translate([0,-a_y-s_y2/2-s_y1/2,0]) rotate([0,90,0]) servo();
      }
    }
  }
}


/*  Jambe (/!\ eq Arduino)
================================ */
//jambe(110,10,90);
module jambe(x, y, z){
  color([1,0,0]) translate([25,0,0]) cube([50,1,1], true);
  color([0,1,0]) translate([0,50,0]) cube([1,100,1], true);
  color([0,0,1]) translate([0,0,38]) cube([1,1,75], true);
	  
  u=sqrt(x*x+y*y);
  i=x*L1/u;
  j=y*L1/u;
    theta = atan(i/j);
  
  v=sqrt(z*z+(L1-u)*(L1-u));
  w=sqrt(L3*L3+l3*l3);
  alpha=acos((v*v+L2*L2-w*w)/(2*L2*v));
  beta=asin((L1-u)/z);
    phi = 360+(alpha-beta);

  epsil=acos((L2*L2+w*w-v*v)/(2*L2*w));
    psi = epsil-90+atan(L3/l3);


  % rotate([0,0,-theta]) translate([-1,0,-z]) cube([2,u,2]);
  echo("i/j : ",i/j );
  echo("theta : ",theta,  "         phi : ",phi,  "         psi : ",psi );

  translate([0,0,-(hauteur+s_z2/2-s_z1/2)+c_z/2+e]){
    cuisse(theta, phi);
    rotate([0,0,-theta]){
      translate([0,2*d_supServ,0]){
        rotate([phi,0,0]){
          translate([0,0,-a_y-s_y2/2-s_y1/2]) support3(psi);
        }
      }
    }
  }
}


//jambe2(0,140,90);
//module jambe2(x, y, z){
//  color([1,0,0]) translate([25,0,0]) cube([50,1,1], true);
//  color([0,1,0]) translate([0,100,0]) cube([1,200,1], true);
//  color([0,0,1]) translate([0,0,25]) cube([1,1,50], true);
// % translate([0,0,-z-2]) cube([x+2,y+2,1]);
//	  
//  u = sqrt(x*x+y*y);
//
//  i = y*L1/u;
//  j = x*L1/u;
//    theta = -atan(j/i);
//
//  n = sqrt(z*z+(u-sqrt(i*i+j*j))*(u-sqrt(i*i+j*j)));
//  alpha = acos((L2*L2+n*n-L3*L3)/(2*L2*n));
//  beta = asin(z/n);
//    phi = alpha-beta;
//  
//  gamma = acos((L2*L2+L3*L3-n*n)/(2*L2*L3));
//    psi = 180-gamma;
//
//  //echo("theta : ",theta,  "         phi : ",phi,  "         psi : ",psi );
//  echo("theta : ",theta+90,  "         phi : ",phi+90,  "         psi : ",180-psi );
//
//  translate([0,0,-(hauteur+s_z2/2-s_z1/2)+c_z/2+e]) rotate([0,0,180]){
//    cuisse(theta, phi);
//    rotate([0,0,theta]){
//      translate([0,-2*d_supServ,0]){ 
//        rotate([-phi,0,0]){
//          translate([0,-a_y-s_y2/2-s_y1/2,0]) support3(psi);
//        }
//      }
//    }
//  }
//}