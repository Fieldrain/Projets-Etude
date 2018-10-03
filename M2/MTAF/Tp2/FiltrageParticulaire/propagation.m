function Particules = propagation(Particules,Config,Estimation,frame)
	mode = Config.dynamique ;
	if mode==1 && frame>2
		Particules(:,1)=Particules(:,1)+(Estimation(frame-1,1)-Estimation(frame-2,1)) ;
		Particules(:,2)=Particules(:,2)+(Estimation(frame-1,2)-Estimation(frame-2,2)) ;
	elseif mode==2 && frame>3
		Particules(:,1)=Particules(:,1)+(2*Estimation(frame-1,1)-3*Estimation(frame-2,1)+Estimation(frame-3,1)) ;
		Particules(:,2)=Particules(:,2)+(2*Estimation(frame-1,2)-3*Estimation(frame-2,2)+Estimation(frame-3,2)) ;
	end
	
	alea = Config.sigma_propagation*randn(Config.nombre_de_particule,2);
	Particules(:,1) = round(Particules(:,1) +alea(:,1)) ;
	Particules(:,2) = round(Particules(:,2) +alea(:,2)) ;
	
	limI=zeros(Config.nombre_de_particule,1) ;		limI(:)=1;
	limW=zeros(Config.nombre_de_particule,1) ;		limW(:)=1000;
	limH=zeros(Config.nombre_de_particule,1) ;		limH(:)=1000;

	Particules(:,1) = min(Particules(:,1),limW) ;
	Particules(:,1) = max(Particules(:,1),limI) ;
	Particules(:,2) = min(Particules(:,2),limH) ;
	Particules(:,2) = max(Particules(:,2),limI) ;
