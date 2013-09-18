//triangleRect(x,y,Z);  prisme triangle rectangle centré sur l'angle droit.



/*  Formes
================================ */
//triangleRect(6,4,10);
module triangleRect(x,y,z){
	difference(){
		cube([x,y,z]);
		translate([x,0,-0.5]){ rotate([0,0,atan(x/y)]) cube([x,sqrt(x*x+y*y),z+1]);}
	}
}

//ellipse(10,15,25,5);
module ellipse(x,y,z,epaisseur) {
	scale ([x/100, y/100, 1]) cylinder(r=50, h=z, center=true);
}


//ellipseTube(10,35,25,5);
module ellipseTube(x,y,z,epaisseur) {  // /!\ 5
	difference(){
		scale ([x/100, y/100, 1]) cylinder(r=50, h=z, center=true);
		scale ([x/100, (y-5)/100, 1]) cylinder(r=50-epaisseur, h=z+1, center=true);
	}
}