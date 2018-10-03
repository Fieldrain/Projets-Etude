#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"  
 
/*------------------------------------*\
			VARIABLES
\*------------------------------------*/ 
#declare R_planet = 6000000 ;
#declare R_sky    = R_planet + 2000 ;

/*------------------------------------*\
			CAMERA
\*------------------------------------*/ 
#declare Camera = camera {
	angle 80
	right    x*image_width/image_height
	location  <0.0 , 500.0 , -6000.0>
	look_at   <0.0 , 0.0 , 0.0>
	}

/*------------------------------------*\
			TEXTURES
\*------------------------------------*/	
#declare T_Sol = texture{
	pigment{
		color rgb<0.35, 0.65, 0.0> * 0.8
		}
	normal{
		bumps   0.75
		scale   0.015
		}
	scale 50
	} 

#declare T_Ciel = pigment{
	color rgb <0.1, 0.3, 0.75> * 0.7
	}
	
#declare T_Nuage = texture{
	pigment{
		bozo turbulence 0.75
		phase 0.05
		color_map{
			[0.00 color rgb     <0.95,  0.95,   0.95> ]
			[0.05 color rgb     <1,     1,      1> * 1.25 ]
			[0.15 color rgb     <0.85,  0.85,   0.85> ]
			[0.55 color rgbt    <1,     1,      1,  1> * 1 ]
			[1.00 color rgbt    <1,     1,      1,  1> * 1 ]
			}
		}   
	finish{
		emission    1
		diffuse     0
		}
	scale 3000
	}

#declare T_Eau = texture{
	Green_Glass
	normal{
		ripples 0.3
		scale 0.25
		turbulence 0.75
		translate< 1,0,2>
		}
	finish{
		ambient 0.45
		diffuse 0.55
		reflection 0.3
		}
	}

#declare T_Gravier = texture{
	pigment{
		granite 
		color_map{
			[0.1 color rgb<3,3,1.5>]
			[0.3 color rgb<2,1.5,1>]
			[1.0 color rgb<1.5,1,0.8>]
			} 
		turbulence  0.5
		}
	scale 0.005
	normal{
		bumps 1 
		scale 0.005
		}
	finish{
		phong 0.8
		}
	}

/*------------------------------------*\
			SOLEIL
\*------------------------------------*/
#declare Soleil =light_source{
	<1000, 2500, -2000> * 100
	color White
	}

/*------------------------------------*\
			SOL
\*------------------------------------*/
#declare Sol = object{
	sphere{
		<0, -R_planet, 0>, R_planet  
		texture{T_Sol}
		}
	}

/*------------------------------------*\
			EAU
\*------------------------------------*/
#declare Eau = object{
	sphere{
		<0, -R_planet, 0>, (R_planet - 0.001)  
		texture{T_Eau}
		interior{I_Glass}
		}
	}
	
#macro Ciel()
/*------------------------------------*\
			HORRIZON
\*------------------------------------*/
fog{
	fog_type    2
	distance    10000
	color       rgb<1, 1, 1> * 0.9
	fog_offset  0.1
	fog_alt     20
	turbulence  1.8
	}


/*------------------------------------*\
			CIEL
\*------------------------------------*/
sky_sphere{
	pigment{T_Ciel}
	}

/*------------------------------------*\
			NUAGES
\*------------------------------------*/
sphere{
	<0, -R_planet, 0>, R_sky  hollow
	texture{
		pigment{
			bozo turbulence 0.75
			phase 0.05
			color_map{
				[0.00 color rgb     <0.95,  0.95,   0.95> ]
				[0.05 color rgb     <1,     1,      1> * 1.25 ]
				[0.15 color rgb     <0.85,  0.85,   0.85> ]
				[0.55 color rgbt    <1,     1,      1,  1> * 1 ]
				[1.00 color rgbt    <1,     1,      1,  1> * 1 ]
				}
			}   
		finish{
			emission    1
			diffuse     0
			}
		scale 3000
		}
	}
#end

/*------------------------------------*\
			SCENE
\*------------------------------------*/
/*------------Coccinelle--------------*/
#macro Patte(RY, TX, TY, TZ)
object{
	union{
		sphere{
			<0, 0, 0> 2
			}
		intersection{
			quadric{
				<0, 1, 1>, <0, 0, 0>, <0, 0, 0>, -1
				}
			box{
				<0, -1, -1>, <10, 1, 1>
				}
			}
		sphere{
			<10, 0, 0> 1.333
			}
		intersection{
			quadric{
				<0, 1, 1>, <0, 0, 0>, <0, 0, 0>, -1
				}
			box{
				<0, -1, -1>, <10, 1, 1>
				}
			rotate      <0, 0, -40>
			translate   <10, 0, 0>
			}
		intersection{
			quadric{
				<1, 1, 1>, <0, 0, 0>, <0, 0, 0>, -1
				}
			box{
				<-1, -0.75, -1> <1, 1, 1>
				}	  
			scale       <3, 1, 2>
			translate   <20, -7,0>
			}
		}
	texture{
		pigment{
			color rgb <0, 0, 0>
			}   
		}
	rotate      <0, RY, 0>
	translate   <TX, TY, TZ>
	}
#end
	
#macro coccinelle(RX,RY,RZ,TX,TY,TZ)
union{
	Patte(-20, 10, -1.5, 10)
	Patte(0, 13, -1.5, 0)
	Patte(20, 10, -1.5, -10)
	Patte(160, -10, -1.5, -10)
	Patte(180, -13, -1.5, 0)
	Patte(200, -10, -1.5, 10)
	object{
		quadric{
			<1, 1, 1>, <0, 0, 0>, <0, 0, 0>, -1
			}
		scale <7, 6, 7>
		texture{
			pigment{
				color rgb<0,0,0>
				}
			}
		translate <0, 4, 18>
		}
	object{
		intersection{
			quadric{
				<1, 1, 1>, <0, 0, 0>, <0, 0, 0>, -1
				scale <-20, 16, 20>
				texture{ pigment{image_map {png "image/wings.png"  map_type 1} rotate<0,90,0>}}
				}

			box{
				<-25, 0, -25>, <25, 20, 25>
				pigment{
					color rgb <0.111, 0.111, 0.333>
					}   
				}
			}
		}
	scale       <0.03,0.03,0.03>
	rotate      <RX, RY, RZ>
	translate   <TX, TY, TZ>
	}
#end

/*---------------Arbre----------------*/
#declare Arbre =
union{
	cylinder{
		<0,-20,0><0,200,0> 20
		pigment{
			image_map{
				jpeg "image/tronc.jpg" 
				map_type 1
				}
			}
		}

	sphere{
		<0,200,0> 100
		pigment{
			image_map{
				jpeg "image/feuille.jpg"
				map_type 0
				}
			scale<100,1,1>
			}
		}
	}	

/*--------------Fleur-----------------*/
#macro decoupe_sphere() 
intersection { 
			sphere { <5,5,5> 5 pigment {Pink}} 
			sphere { <10,5,5> 5 pigment {Pink}}     
			}
#end

#macro decoupe_inferieure()
difference {
			 decoupe_sphere() 
			 box{<0,0,0> ,<10,10,10> pigment {Pink} translate<0,-5.2,0>}
			} 

#end 

#macro decoupe_superieure(placement, rotation)
difference {
			decoupe_inferieure()  
			box{<0,0,0> ,<10,10,10> pigment {Pink} translate<0,5,0>}
			translate placement
			rotate rotation
		   }
#end  
 
#declare Fleur = 
	union {
		decoupe_superieure(<0,0,0>, <1,1,1>) 
		decoupe_superieure(<-4,0,-5>, <1,-45,1>)
		decoupe_superieure(<-5,0,-5>, <1,90,1>)
		decoupe_superieure(<-0.5,0,-9>, <1,45,1>)  
		decoupe_superieure(<0,0,-15>, <1,1,1>)
		decoupe_superieure(<-4,0,-19>, <1,-45,1>)
		decoupe_superieure(<-5,0,10>, <1,90,1>)
		decoupe_superieure(<-0.5,0,6>, <1,45,1>) 
		difference {
					sphere {<1,1,1> 4 pigment {Yellow} translate <7,2.5,-4>}
					box{<0,0,0> <10,10,10> pigment {Yellow} translate <3,-5.3,-7>} 
					}
		cylinder {<0,-10,0> <0,15,0> 1 pigment {Green} translate <7.5,-10,-3>}
		scale 0.3
		}

/*------------Plantaison--------------*/
#macro Plantaison ( Object, 			// Objet à planter
					Nombre_X, 			// Nombre d'éléments dans l'axe des X
					Nombre_Z, 			// Nombre d'éléments dans l'axe des Z
					Distance_X, 		// Distance de base X
					Distance_Z, 		// Distance de base Z
					Angle_Inclinaison, 	// Angle d'inclinaison
					Taille, 			// Taille aléatoire
					Seed_0, 			// Ramdom seed inclinaison X 
					Seed_1, 			// Ramdom seed rotation Y
					Seed_2, 			// Ramdom seed scale
					Seed_3 				// Ramdom seed translate X Z
					)

#local Random_0 = seed (Seed_0); 
#local Random_1 = seed (Seed_1); 
#local Random_2 = seed (Seed_2); 
#local Random_3 = seed (Seed_3);

union{
	#local NbX = 0;
	#while (NbX< Nombre_X+1)
		#local NbZ = 0;
		#while (NbZ< Nombre_Z+1) 
		object{
			Object
			rotate 	<Angle_Inclinaison*2*(0.5-rand(Random_0)),0,0>
			rotate 	<0,360*rand(Random_1),0>
			scale 	Taille*rand(Random_2)
			translate <NbX*Distance_X+2*(-0.5+rand(Random_3)), 0, NbZ*Distance_Z+2*(-0.5+rand(Random_3))>
			} 
		#local NbZ = NbZ + 1;
		#end
	#local NbX = NbX + 1;
	#end
	}
#end

#declare Vegetation =
union{
	// Fleur
	object{
		Fleur
		translate <-2,0,-5000>
		}

	// Champ Fleurs
	object{ Plantaison( object{Fleur}, 180, 180, 25, 25, 
						10, 0.50, 6432, 1153, 342, 2655)
			scale <1,1,1>*1
			rotate<0,0,0> 
			translate<-2500, 0, -5000>}

	// Foret Gauche
	object{ Plantaison( object{Arbre}, 10, 400, 50, 50, 
						10, 0.50, 6432, 1153, 342, 2655)
			scale <1,1,1>*1
			rotate<0,0,0> 
			translate<-3500, 0, -5000>}

	// Foret Droite
	object{ Plantaison( object{Arbre}, 10, 400, 50, 50, 
						10, 0.50, 6432, 1153, 342, 2655)
			scale <1,1,1>*1
			rotate<0,0,0> 
			translate<3000, 0, -5000>}
	
	// Foret Fond
	object{ Plantaison( object{Arbre}, 10, 150, 50, 50, 
						10, 0.50, 6432, 1153, 342, 2655)
			scale <1,1,1>*1
			rotate<0,90,0> 
			translate<-3500, 0, 15500>}
	// Foret Ile
	}

#declare Gravier =
box{
	<-2900, 0, -100>, <2900, 0.001, 100>
	texture{T_Gravier}       
	}
	
#declare Plan_eau =
union{
	box{<-2000, 0.1, 10000>, <1000, -50, 15000>}
	object{
    	box{<-1400, -0.01, 0>, <750, -50, 400>}      //180
	    rotate <0,-45,0>
	    translate <475,0,9500>
	}
	object{ 
    	box{<-750, -0.01, 0>, <1400, -50, 400>}
	    rotate <0,45,0>
	    translate <-1475,0,9500>
	    }
	texture{pigment{color Brown}}
    }


/*------------------------------------*\
			EXEMPLE UTILISATION
\*------------------------------------*/


/*camera{
	Camera
	}
	
Soleil
Ciel()
// Sol + Trou pour l'eau
difference{
	object{Sol}
	object{Plan_eau}
	}
Eau
Vegetation
Gravier
coccinelle(0, 0, 0, 0, 2, -4999)  */
