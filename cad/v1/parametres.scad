/* Quadrupède - 15/07/2011 
-------------------------------------------------------- */

resolution = 10;
pi = 180;
m = 1; // marge pour la fonction difference() d'Openscad
e = 1.6;
M2 = 2/2; 
M3 = 3/2; 
M4 = 4/2; 
M5 = 5/2; 



/*  Servo 
================================ */
s_x1 = 11.7;
s_y1 = 29.75;
s_z1 = 29.44;

hauteur = 19.8;
s_x2 = 11.7;
s_y2 = 40.6;
s_z2 = 2.00;

trou = 2;
disk_r1 = 7.95/2;      // petit
disk_h1 = 36.15-s_z1;
disk_r2 = 16.9/2;      // grand
disk_h2 = 1.61;

a_y = 10.033;  // arbre
a_z = 36.15;

c_x = 9;  // caoutchouc
c_y = 6.35;
c_z = 5.95;


sup_x = 2*disk_r2;
sup_y = s_z1+2*disk_h1;
sup_z = e;
d_supServ = 20;

axe_r = 3.5;  // manchon taraudé (MCL4-15)
axe_h = 15;
ent_r = 5;  // entretoise cylindrique (PLN6-5/B)
ent_h = 6;

patte_x = 1.6*(2*s_y1);
courbe_x = 30;
courbe_y = patte_x;
courbe_z = e+1;


/*  Plaque 1 
================================ */
AH = 100;
AI = AH/sqrt(2);
DE = 30;
AB = DE/2;
BJ = (AH-DE)/2;
JC = AH/2-2*AB;




/*  Plaque 2 
================================ */
LM = s_x1+10;
ON = 105;


L1 = 2*d_supServ;
L2 = a_y+s_y2/2+s_y1/2;
L3 = patte_x+sup_x/2;


  //echo("L1 : ",L1+e,  "         L2 : ",L2,  "         L3 : ",L3 );

