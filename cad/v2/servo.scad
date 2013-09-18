/* Quadrup�de - 15/07/2011 
-------------------------------------------------------- */
include<parametres.scad>;
include<shapes.scad>;


/*  Servo 
================================ */
//servo();
module servo(){
  color([80/255,80/255,80/255]){
    translate([0,s_y1/2-a_y,0]){
      cube([s_x1, s_y1, s_z1], true);
      translate([0,0,hauteur+s_z2/2-s_z1/2]) cube([s_x2, s_y2, s_z2], true);
    }
    translate([0,0,s_z1/2+disk_h1/2]) cylinder(r=disk_r1, h=disk_h1, center=true);
    translate([0,0,s_z1/2+disk_h1-disk_h2/2-1]) cylinder(r=disk_r2, h=disk_h2, center=true);
  }
}

//caoutchouc();
module caoutchouc(){
  difference(){
    cube([c_x,c_y,c_z], true);
    cylinder(r=M3, h=7, center=true);
  }
}

//servoCaout();
module servoCaout(){
  color([130/255,130/255,130/255]){
    servo();
    translate([0,s_y1/2+a_y-1.5,hauteur+s_z2/2-s_z1/2]) caoutchouc();
    translate([0,-s_y1/2+1.5,hauteur+s_z2/2-s_z1/2]) caoutchouc();
  }
}

//manchon();
module manchon(){
  color([200/255,200/255,200/255]){
    translate([0,0,-s_z1/2-axe_h/2]) cylinder(r=axe_r, h=axe_h, center=true);
  }
}

//entretoise();
module entretoise(){
  color([250/255,250/255,250/255]){
    translate([0,0,-s_z1/2-ent_h/2]) cylinder(r=ent_r, h=ent_h, center=true);
  }
}

//support1(0);
module support1(theta){
  rotate([0,0,-theta]){
    difference(){
      union(){
        translate([0,d_supServ,0]) rotate([90,0,0]) cube([sup_x,sup_y,sup_z], true);

        translate([0,d_supServ/2,s_z1/2+disk_h1-disk_h2/2-1+disk_h2]) cube([sup_x,d_supServ,e], true);
        translate([0,0,s_z1/2+disk_h1-disk_h2/2-1+disk_h2]) cylinder(r=disk_r2, h=e, center=true);
        mirror([0,0,1]){
          translate([0,d_supServ/2,s_z1/2+disk_h1-disk_h2/2-1+disk_h2]) cube([sup_x,d_supServ,e], true);
          translate([0,0,s_z1/2+disk_h1-disk_h2/2-1+disk_h2]) cylinder(r=disk_r2, h=e, center=true);
        }
      }

    for(i = [1, 2, 3, 4]){ 
      rotate([0,0,i*90]) translate([0,6,s_z1/2]) cube([trou,trou,s_z1],true);
    }
    translate([0,0,s_z1/2]) cylinder(r=disk_r1, h=s_z1, center=true);
    translate([0,0,-s_z1/2]) cylinder(r=axe_r, h=s_z1, center=true);

    for(i = [1, 2, 3, 4]){
      rotate([0,i*90,0]) translate([0,0,6]) cube([trou,2*s_z1,trou],true);
    }
    rotate([90,0,0]) cylinder(r=disk_r1, h=3*d_supServ, center=true);
    }

    //entretoise();
    manchon();
  }
}

//support2(0);
module support2(theta){
  union(){
    support1(theta);
    rotate([0,90,-theta]) translate([0,2*d_supServ,0]) mirror([0,1,0]) support1(0);

    rotate([0,0,-theta]) translate([0,d_supServ,0]) rotate([90,0,0]) for(i = [1, 2, 3, 4]){
      rotate([0,0,i*90]) difference(){
        translate([(sup_x+(sup_y-sup_x)/2)/2,(sup_x+(sup_y-sup_x)/2)/2,0]) cube([(sup_y-sup_x)/2,(sup_y-sup_x)/2,e], true);
        translate([sup_y/2,sup_y/2,0]) cylinder(r=(sup_y-sup_x)/2, h=e+1, center=true);
      }
    }
  }
  
}

//support_patte(0);
module support_patte(theta){
    intersection(){
      difference(){
        union(){
          rotate([0,90,0]) rotate([0,0,theta]) translate([patte_x/4+sup_x/2,-d_supServ,0]) rotate([90,0,0]) cube([patte_x/2,sup_y,2*d_supServ], true);
          rotate([theta,0,0]) translate([0,-d_supServ,-sup_x/2-courbe_y/2]) rotate([90,0,0]) ellipse(sup_y-courbe_x,courbe_y,2*d_supServ);
          rotate([theta,0,0]) translate([0,-sup_y/2-0.6,0]) cube([sup_y,3*e/2,sup_x], true);
        }

        rotate([theta,0,0]){
          translate([sup_y/2,-d_supServ,-sup_x/2-courbe_y/2]) rotate([90,0,0]) ellipse(courbe_x,courbe_y,2*d_supServ);
          mirror([1,0,0])
            translate([sup_y/2,-d_supServ,-sup_x/2-courbe_y/2]) rotate([90,0,0]) ellipse(courbe_x,courbe_y,2*d_supServ);
        }
        for(i = [1, 2, 3, 4]){ 
          rotate([theta,0,0]) rotate([0,i*90,0]) translate([0,0,6]) cube([trou,2*s_z1,trou],true);
        }
      }

     rotate([theta,0,0]) rotate([0,90,0]) ellipseTube(2*patte_x+sup_x,2*d_supServ+e+5,sup_y, 2*e);
    }

}

//support3(0);
module support3(theta){
  rotate([-180,0,0]){
    rotate([0,-90,0]) support1(theta);
    rotate([0,0,180]) support_patte(-theta);
  }
}

