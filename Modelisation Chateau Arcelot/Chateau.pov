#version 3.7;
global_settings { assumed_gamma 1.0 }

#include "Dependance.pov"
#include "Centre.pov"
#include "Exterieur.pov"
#include "Pont.pov"

#macro animation_timelaps()
    #local rouge=1;
    #local vert = 0.3+clock;
    #local bleu = 0+clock;
    #if (clock < 0.5)
        light_source {<100000000, 100000000, 1500> color rgb<rouge,vert,bleu> rotate y*200*clock }
    #else
        #local vertD = 1.3-clock;
        #local bleuD = 1-clock;
        light_source {<100000000, 100000000, 1500> color rgb<rouge,vertD,bleuD> rotate y*200*clock }
    #end


#end

#macro Chateau(X,Y,Z)
union{
      Base(0,0,0)
      dependance_gauche(<-2800,0,-400>, <0,0,0>)
      dependance_gauche(<2800,0,400>, <0,180,0>) 


      translate<X,Y,Z>
}

#end


Soleil
Ciel()
difference{
	object{Sol}
	object{Plan_eau}
	}
Eau
Vegetation
Gravier


#declare hauteurCoccinelle = 2;
#declare distanceZCoccinelle = -4999;
#declare hauteurMaxCamDecollage = 200;
#declare hauteurMaxCamDecollage2 = 850;  

/*---------------------
1ere Partie - Zoom Coccinelle
---------------------*/
/*#declare camY = 6+hauteurCoccinelle-clock*5;
#declare camZ = distanceZCoccinelle-5+clock*5;
camera{location<0,camY,camZ> look_at<0,hauteurCoccinelle,distanceZCoccinelle+2>} */

/*---------------------
2eme Partie - Redressage camera 
---------------------*/  

/*#declare lookY = hauteurCoccinelle*clock; 
#declare lookZ = distanceZCoccinelle+5+hauteurCoccinelle*clock;    
camera{location<0,hauteurCoccinelle,distanceZCoccinelle+5> look_at<0.01,lookY,lookZ>}   */
  


/*---------------------
3eme Partie - Decollage
---------------------*/ 


/*#declare camY = hauteurMaxCamDecollage*clock+50;
camera{location<0,camY,distanceZCoccinelle+5> look_at<0,camY,0>}*/
                          
                                                                         
/*---------------------
4eme Partie - Avant
---------------------*/   


/*#declare distanceZStop = -2500;
#declare camZ = (distanceZCoccinelle +5 -distanceZStop)*(1-clock)+distanceZStop;
camera{location<0,hauteurMaxCamDecollage+50,camZ> look_at<0,hauteurMaxCamDecollage+50,0>}*/  


/*---------------------
5eme Partie - Avant
---------------------*/   

/* 
#declare distanceZCoccinelle = -2500;
#declare distanceZStop = -700;
#declare camZ = (distanceZCoccinelle +5 -distanceZStop)*(1-clock)+distanceZStop;
camera{location<0,hauteurMaxCamDecollage+50,camZ> look_at<0,hauteurMaxCamDecollage+50,0>} */   


/*---------------------
6eme Partie - Piece a gauche
---------------------*/  
/*
#declare lookX = sin(pi*(clock/2))*-799;                                                      
camera{location<0,hauteurMaxCamDecollage+50,-800> look_at<lookX,hauteurMaxCamDecollage+50,0>}  */

                                                                         
/*---------------------
7eme Partie - Piece gauche a droite
---------------------*/  

/*#declare lookX = cos(pi*clock)*-799;
camera{location<0,hauteurMaxCamDecollage+50,-800> look_at<lookX,hauteurMaxCamDecollage+50,0>}  */     

/*---------------------
8eme Partie - Piece droite au milieu
---------------------*/  

/*#declare lookX = sin(pi*(0.5-clock/2))*799;
camera{location<0,hauteurMaxCamDecollage+50,-800> look_at<lookX,hauteurMaxCamDecollage+50,0>}  */  


/*---------------------
9eme Partie - Avant, sortir de la premiere piece
---------------------*/ 

/*#declare camZ = (-800-25)*(1-clock)+25;
camera{location<0,hauteurMaxCamDecollage+50,camZ> look_at<0,hauteurMaxCamDecollage+50,250>}   */ 



/*---------------------
10eme Partie - Piece a gauche
---------------------*/  

/*#declare lookX = sin(pi*(clock/2))*-100;                                                      
camera{location<0,hauteurMaxCamDecollage+50,25> look_at<lookX,hauteurMaxCamDecollage+50,100>} */
  
                                                                       
/*---------------------
11eme Partie - Piece gauche a droite
---------------------*/  

/*#declare lookX = cos(pi*clock)*-100;
camera{location<0,hauteurMaxCamDecollage+50,25> look_at<lookX,hauteurMaxCamDecollage+50,100>}  */     

/*---------------------
12eme Partie - Piece droite au milieu
---------------------*/  

/*#declare lookX = sin(pi*(0.5-clock/2))*100;
camera{location<0,hauteurMaxCamDecollage+50,25> look_at<lookX,hauteurMaxCamDecollage+50,100>}  */  


/*---------------------
13eme Partie - Avant, sortir de la premiere piece
---------------------*/ 
   
/*#declare camZ = 4975*clock+25;
camera{location<0,hauteurMaxCamDecollage+50,camZ> look_at<0,hauteurMaxCamDecollage+50,5500>} */                                                                                              

//camera{location<0,hauteurMaxCamDecollage+50,25> look_at<0,hauteurMaxCamDecollage+50,2000>}    //test pour voir la table   


/*---------------------
14eme Partie - Demi-tour camera
---------------------*/ 
   
/*#declare theta = pi * clock;  
#declare lookX = 10000 * sin(theta);
#declare lookZ = 10000 * cos(theta);                                                                
camera{location<0,hauteurMaxCamDecollage+50,4999> look_at<lookX,hauteurMaxCamDecollage+50,lookZ>}   */ 
                                                                                                   

/*---------------------
15eme Partie - Décollage
---------------------*/ 
   
/*#declare camY = hauteurMaxCamDecollage2*clock+hauteurMaxCamDecollage+50;
camera{location<0,camY,4999> look_at<0,camY,0>}
                                                */
/*---------------------
16eme Partie - Tour
---------------------*/ 

/*
#declare theta = 2 * pi * clock;  
#declare camX = 4999 * sin(theta);
#declare camZ = 4999 * cos(theta);
camera{location<camX,hauteurMaxCamDecollage2+hauteurMaxCamDecollage+50,camZ> look_at<0,hauteurMaxCamDecollage2+hauteurMaxCamDecollage+50,0>}   */

/*---------------------
17eme Partie - Demi-tour camera
---------------------*/ 
   
/*#declare theta = pi * clock;  
#declare lookX = -10000 * sin(theta);
#declare lookZ = -10000 * cos(theta);
camera{location<0,hauteurMaxCamDecollage2+hauteurMaxCamDecollage+50,4999> look_at<lookX,hauteurMaxCamDecollage2+hauteurMaxCamDecollage+50,lookZ>}  */


/*---------------------
17.5 eme Partie - descente
---------------------*/

#declare camY = hauteurMaxCamDecollage2*(1-clock)+hauteurMaxCamDecollage+50;
camera{location<0,camY,4999> look_at<0,camY,10000>}   


/*---------------------
18eme Partie - Direction Pont
---------------------*/ 
   
/*#declare camZ = clock*4200+5000;
camera{location<0,hauteurMaxCamDecollage+50,camZ> look_at<0,hauteurMaxCamDecollage+50,10000>}*/ 


/*---------------------
19eme Partie - Demi tour camera
---------------------*/ 
   
/*#declare theta = pi * clock;  
#declare lookX = 18600 * sin(-theta);
#declare lookZ = 18600 * cos(-theta);
camera{location<0,hauteurMaxCamDecollage+50,9300> look_at<lookX,hauteurMaxCamDecollage+50,lookZ>} */  


/*---------------------
19eme Partie - TimeLaps
---------------------*/

/*

/!\ PENSER A ENLEVER SOLEIL, CA LE FERA MIEUX JE PENSE POUR LE TIMELAPSE /!\ 

*/

/*animation_timelaps()
camera{location<0,hauteurMaxCamDecollage+50,9300> look_at<0,hauteurMaxCamDecollage+50,0>} */  
 




coccinelle(0, 0, 0, 0, hauteurCoccinelle, distanceZCoccinelle)

Chateau(0,0,0)

Pont(-1050,-10,9300,45)


