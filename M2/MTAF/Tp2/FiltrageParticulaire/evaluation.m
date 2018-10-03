function critere = evaluation(Config,Estimation,VT)
	critere=0;
	
	for f=1:Config.nombre_de_frame
		dx = Estimation(f,1)-VT(f,2) ;
		dy = Estimation(f,2)-VT(f,1) ;
		
		critere=critere+ dx*dx+dy*dy ;
	end
	critere = sqrt(critere)/Config.nombre_de_frame;
	
