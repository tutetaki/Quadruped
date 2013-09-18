/* Quadrup�de - 15/07/2011 
-------------------------------------------------------- */
include<parametres.scad>;
include<corps.scad>;


/*  Partie Inf�rieure 
================================ */
rho = AH/3;
theta = 0;
phi = 0;
i = 0;
j = 0;
k = 0;

x1 = 90;
y1 = 0;
z1 = 100;

x2 = 90;
y2 = 0;
z2 = 100;

x3 = 90;
y3 = 0;
z3 = 100;

x4 = 90;
y4 = 0;
z4 = 100;


partInf(rho,theta,phi,i,j,k,  x1,y1,z1  ,x2,y2,z2  ,x3,y3,z3  ,x4,y4,z4);
module partInf(rho,theta,phi,i,j,k,  x1,y1,z1  ,x2,y2,z2  ,x3,y3,z3  ,x4,y4,z4){
  x = -rho*sin(theta)*cos(phi);
  y = rho*cos(theta)*cos(phi);
  z = rho*sin(phi); // non implement�

  echo("x : ",x);
  echo("y : ",y);
  echo("z : ",z);

  //rotate([0,-phi,theta]) translate([i,j,k]) corps();

  rotate([0,0,315]) // I
    translate([x, y,  k]) 
    rotate([0,0,90]) jambe(x1,  y1,  z1);

  rotate([0,0,45])  // II
    translate([x, y,  k]) 
    rotate([0,0,90]) jambe(x2,  y2,  z2);

  rotate([0,0,135]) // III
    translate([x, y,  k]) 
    rotate([0,0,90]) jambe(x3,  y3,  z3);

  rotate([0,0,225]) // IV
    translate([x, y,  k]) 
    rotate([0,0,90]) jambe(x4,  y4,  z4);
}

//
//partInf(rho,theta,phi,i,j,k,  x1,y1,z1  ,x2,y2,z2  ,x3,y3,z3  ,x4,y4,z4);
//module partInf(rho,theta,phi,i,j,k,  x1,y1,z1  ,x2,y2,z2  ,x3,y3,z3  ,x4,y4,z4){
//  x = -rho*sin(theta)*cos(phi);
//  y = rho*cos(theta)*cos(phi);
//  z = rho*sin(phi); // non implement�
//
//  echo("x : ",x);
//  echo("y : ",y);
//  echo("z : ",z);
//
//  rotate([0,-phi,theta]) translate([i,j,k]) corps();
//
//  rotate([0,0,315]) // I
//    translate([x+sin(45)*i-sin(45)*j,  y+cos(45)*i+cos(45)*j,  k]) 
//    rotate([0,0,-90]) jambe(x1-x-sin(45)*i+sin(45)*j,  y1-y-cos(45)*i-cos(45)*j,  z1+k);
//
//  rotate([0,0,45])  // II
//    translate([x+sin(45)*i+sin(45)*j,  y-cos(45)*i+cos(45)*j,  k]) 
//    rotate([0,0,-90]) jambe(x2-x-sin(45)*i-sin(45)*j,  y2-y+cos(45)*i-cos(45)*j,  z2+k);
//
//  rotate([0,0,135]) // III
//    translate([x-sin(45)*i+sin(45)*j,  y-cos(45)*i-cos(45)*j,  k]) 
//    rotate([0,0,-90]) jambe(x3-x+sin(45)*i-sin(45)*j,  y3-y+cos(45)*i+cos(45)*j,  z3+k);
//
//  rotate([0,0,225]) // IV
//    translate([x-sin(45)*i-sin(45)*j,  y+cos(45)*i-cos(45)*j,  k]) 
//    rotate([0,0,-90]) jambe(x4-x+sin(45)*i+sin(45)*j,  y4-y-cos(45)*i+cos(45)*j,  z4+k);
//}