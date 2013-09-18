/* Quadrupède - 15/07/2011 
-------------------------------------------------------- */
include<parametres.scad>;
include<corps.scad>;
include<plaques.scad>;


//plaque1();
//rotate([0,0,45]) plaque2();

//rotate([0,0,90]) support1(); 
module support1(){ 

    difference(){
      union(){
        cube([sup_x,sup_y,sup_z], true);

        translate([0,(sup_y+d_supServ)/2,0]) cube([sup_x,d_supServ,e], true);
        translate([0,(sup_y+d_supServ)/2+disk_r2+e,0]) cylinder(r=disk_r2, h=e, center=true , $fn = 10);
        mirror([0,1,0]){
          translate([0,(sup_y+d_supServ)/2,0]) cube([sup_x,d_supServ,e], true);
          translate([0,(sup_y+d_supServ)/2+disk_r2+e,0]) cylinder(r=disk_r2, h=e, center=true , $fn = 10);
        }
      }


   translate([0,-(sup_y+d_supServ)/2-disk_r2-e,0]) for(i = [1, 3]){ 
      rotate([0,0,i*90]) translate([4,0,0]) cube([trou+4,trou,10],true);
    }
    translate([0,-(sup_y+d_supServ)/2-disk_r2-e,0]) cylinder(r=disk_r1, h=10, center=true  , $fn = 10);
    translate([0,(sup_y+d_supServ)/2+disk_r2+e,0]) cylinder(r=axe_r, h=10, center=true , $fn = 10);

    for(i = [1, 3]){ 
      rotate([0,0,i*90]) translate([4,0,0]) cube([trou+4,trou,10],true);
    }
    for(i = [ 2, 4]){ 
      rotate([0,0,i*90]) translate([4,0,0]) cube([trou+4,trou,10],true);
    }
    rotate([0,0,0]) cylinder(r=5, h=10, center=true , $fn = 10);
    
    translate([0,sup_y/2,0.8]) rotate([45,0,0])  cube([sup_x+1,e,e], true);
    translate([0,-sup_y/2,0.8]) rotate([45,0,0])  cube([sup_x+1,e,e], true);
    
  }
}

translate([0,0,0]) rotate([0,0,-90]) support_patte();
module support_patte(theta){
  translate([0,-patte_x/2,d_supServ]) rotate([90,0,0]){
    intersection(){
      difference(){
        union(){
          rotate([0,90,0]) translate([patte_x/4+sup_x/2,-d_supServ,0]) rotate([90,0,0]) cube([patte_x/2,sup_y,2*d_supServ], true);
          translate([0,-d_supServ,-sup_x/2-courbe_y/2]) rotate([90,0,0]) ellipse(sup_y-courbe_x ,courbe_y,2*d_supServ);
          translate([0,-sup_y/2-0.6,0]) cube([sup_y,3*e/2,sup_x], true);
        }

        translate([sup_y/2,-d_supServ,-sup_x/2-courbe_y/2]) rotate([90,0,0]) ellipse(courbe_x,courbe_y,2*d_supServ);
        mirror([1,0,0])
          translate([sup_y/2,-d_supServ,-sup_x/2-courbe_y/2]) rotate([90,0,0]) ellipse(courbe_x,courbe_y,2*d_supServ);
        rotate([0,1*90,0]) translate([0,0,6]) cube([trou,2*s_z1,trou],true);
        rotate([0,2*90,0]) translate([0,0,6]) cube([trou,2*s_z1,trou],true);
        rotate([0,3*90,0]) translate([0,0,6]) cube([trou,2*s_z1,trou],true);
        rotate([0,4*90,0]) translate([0,0,6]) cube([trou,2*s_z1,trou],true);
      }  

      rotate([0,90,0]) ellipseTube(2*patte_x+sup_x,2*d_supServ+e+5,sup_y, 2*e);
    }
  }
}















