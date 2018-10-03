function Config = chargeConfiguration()
	field1='nom_sequence';
	value1= "Frame";
	field2='nombre_de_frame'; 
	value2=  15;
	field3='nombre_de_particule'; 
	value3=  1000;
	field4='estimation_instant_zero'; 
	value4=  [457 375];
	field5='dynamique'; 	
	value5=  1;
	field6='mode_estimation'; 
	value6=  0;
	field7='fonction_de_vraisemblance'; 
	value7=  2;
	field8='sigma_propagation';
	value8=  50;
	field9='taille_fenetre_ponderation';
	value9=  10;
	field10='resampling'; 
	value10= "y";
	
	Config = struct(field1,value1,field2,value2,field3,value3,field4,value4,field5,value5,field6,value6,field7,value7,field8,value8,field9,value9,field10,value10);


