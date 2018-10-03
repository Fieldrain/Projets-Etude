function Particules=initialisation(Config)
	Particules=zeros(Config.nombre_de_particule,3);
	Particules(:,1)=Config.estimation_instant_zero(1);
	Particules(:,2)=Config.estimation_instant_zero(2);
	Particules(:,3)=1/Config.nombre_de_particule;

