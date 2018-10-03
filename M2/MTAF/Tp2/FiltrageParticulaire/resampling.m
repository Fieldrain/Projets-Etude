function Particules = resampling(Particules,Config)
	norm=1/Config.nombre_de_particule ;
	Buffer=Particules ;
	cumul=zeros(Config.nombre_de_particule,1) ;
	cumul(1)=Particules(1,3);
	for p=2:Config.nombre_de_particule
		cumul(p)=cumul(p-1)+Particules(p,3);
	end
	cumul=cumul./cumul(Config.nombre_de_particule);
	u=norm*rand(1);
	pos=1;
	for p=1:Config.nombre_de_particule
		while u>cumul(pos)
			pos=pos+1;
		end
		Particules(p,:)=Buffer(pos,:);
		Particules(p,3)=norm ;
		u=u+norm;
	end
