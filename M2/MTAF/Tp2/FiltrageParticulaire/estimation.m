function [x y]=estimation(Particules,Config)
	if Config.mode_estimation==0
		x=0;
		y=0;
		for k=1:Config.nombre_de_particule
			x=x+Particules(k,3)*Particules(k,1) ;
			y=y+Particules(k,3)*Particules(k,2) ;
		end
		x=round(x);
		y=round(y);
	else
		p=round(find(Particules==max(Particules(:,3)))/3);
		x=Particules(p,1) ;
		y=Particules(p,2) ;
	end
	

