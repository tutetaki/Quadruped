include<bitmap.scad>;

scale=1;
res=50;

module d_vector(length, label){
	union(){
		cube([length,scale,1],center=true);
		translate([length/2,0,0]){
			rotate([0,0,45])cube([scale,scale,1],center=true);
			rotate([0,0,45])translate([-scale*3/2,0,0])cube([scale*3,scale,1],center=true);
			rotate([0,0,-45])translate([-scale*3/2,0,0])cube([scale*3,scale,1],center=true);
		}
		translate([-length/2,0,0]){
			cylinder(r=scale,h=1,center=true,$fn=res);
		}
		rotate([0,0,-90])
			translate([-scale*2-scale,-scale*2,0])
				8bit_str(["v",label], 2, scale, 1);
	}
}

module d_length_t1(length, label1){
	union(){
		cube([length,scale,1],center=true);
		translate([length/2,0,0]){
			cube([scale,scale*6,1],center=true);
		}
		translate([-length/2,0,0]){
			cube([scale,scale*6,1],center=true);
		}
		rotate([0,0,-90])
			translate([-scale*6,0,0])
				8bit_str([label1], 1, scale, 1);
	}
}

module d_length_t2(length, label1, label2){
	union(){
		cube([length,scale,1],center=true);
		translate([length/2,0,0]){
			cube([scale,scale*6,1],center=true);
		}
		translate([-length/2,0,0]){
			cube([scale,scale*6,1],center=true);
		}
		rotate([0,0,-90])
			translate([-scale*6,-scale*2,0])
				8bit_str([label1, label2], 2, scale, 1);
	}
}

//todo: Can only do 0-180 degrees. Extend to 360.
module d_angle(a,r,dir,label){
	union(){
		difference(){
			cylinder(r=r+scale/2,h=1,center=true,$fn=res);
			cylinder(r=r-scale/2,h=2,center=true,$fn=res);
			translate([0,-((r+scale/2)+1)/2,0])cube([(r+scale/2)*2+1, (r+scale/2)+1, 2],center=true);
			rotate([0,0,a])translate([0,((r+scale/2)+1)/2,0])
				cube([(r+scale/2)*2+1, (r+scale/2)+1, 2],center=true);
			if(dir==1){
				translate([(r)*cos(a),(r)*sin(a),0])rotate([0,0,a+90])
					translate([-scale/2+0.1,0,0])cube([scale,scale+1,2],center=true);
			}
			else{
				translate([r,0,0])
					translate([0,scale/2+0.1,0])cube([scale+1,scale+1,2],center=true);
			}
		}
		if(dir==1){
			translate([r,0,0])cylinder(r=scale*1.5,h=1,center=true,$fn=res);
			translate([(r)*cos(a),(r)*sin(a),0])rotate([0,0,a+90]){
				rotate([0,0,45])translate([-scale/2,scale/2,0])cube([scale,scale,1],center=true);
				rotate([0,0,45])translate([-scale*6/2,scale/2,0])cube([scale*6,scale,1],center=true);
				rotate([0,0,-45])translate([-scale*6/2,-scale/2,0])cube([scale*6,scale,1],center=true);
			}
		}
		else{
			translate([(r)*cos(a),(r)*sin(a),0])cylinder(r=scale*1.5,h=1,center=true,$fn=res);
			translate([r,0,0])rotate([0,0,-90]){
				rotate([0,0,45])translate([-scale/2,scale/2,0])cube([scale,scale,1],center=true);
				rotate([0,0,45])translate([-scale*6/2,scale/2,0])cube([scale*6,scale,1],center=true);
				rotate([0,0,-45])translate([-scale*6/2,-scale/2,0])cube([scale*6,scale,1],center=true);
			}
		}
		rotate([0,0,a/2-180])
			translate([-scale*8-r,-scale*2,0])
				8bit_str(["a",label], 2, scale, 1);
		translate([r/2,0,0])cube([r,1,1],center=true);
		rotate([0,0,a])translate([r/2,0,0])cube([r,1,1],center=true);
	}
}


