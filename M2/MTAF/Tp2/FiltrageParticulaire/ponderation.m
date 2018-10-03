function Particules = ponderation(Particules,Config,I)
	window=Config.taille_fenetre_ponderation;
	[h w d]=size(I) ;
	if Config.fonction_de_vraisemblance<2
		somme=0;
		for p=1:Config.nombre_de_particule
			w1=min(max(Particules(p,1)-window,1),w) ;
			w2=min(max(Particules(p,1)+window,1),w) ;
			h1=min(max(Particules(p,2)-window,1),h) ;
			h2=min(max(Particules(p,2)+window,1),h) ;			
			
			Icrop=I(w1:w2,h1:h2,:);
			moy= mean(Icrop(:));
			
			if Config.fonction_de_vraisemblance==0
				Particules(p,3)=255-moy;
				somme=somme+255-moy;
			else
				Particules(p,3)=(255-moy)*(255-moy);
				somme=somme+(255-moy)*(255-moy);
			end
		end
		Particules(:,3)=Particules(:,3)./somme;
	elseif Config.fonction_de_vraisemblance<4
		somme=0;
		for p=1:Config.nombre_de_particule
			w1=min(max(Particules(p,1)-window,1),w) ;
			w2=min(max(Particules(p,1)+window,1),w) ;
			h1=min(max(Particules(p,2)-window,1),h) ;
			h2=min(max(Particules(p,2)+window,1),h) ;			
			
			Icrop=I(w1:w2,h1:h2,:);
			v= double(255-min(Icrop(:)));
			
			if Config.fonction_de_vraisemblance==2
				Particules(p,3)=v;
				somme=somme+v;
			else
				Particules(p,3)=v*v;
				somme=somme+v*v;
			end
		end
		Particules(:,3)=Particules(:,3)./somme;
	else
		somme=0;
		for p=1:Config.nombre_de_particule
			x=double(Particules(p,1)) ;
			y=double(Particules(p,2)) ;
			v=double(255-I(x,y,1));
			Particules(p,3)=v;
			somme=somme+v;
		end
		Particules(:,3)=Particules(:,3)./somme;
	end

