function [x y]=visuParticules(Particules,Config,I,frame)
	maxW=max(Particules(:,3));
	for k=1:Config.nombre_de_particule
		w=Particules(k,3)/maxW ;
		if w<0.5
			r=255;
			g=510*w;
		else
			g=255;
			r=510*(1-w);
		end
		I=dessinCroix(I,Particules(k,1),Particules(k,2),r,g,0,5);
	end
	
	%figure;
	[x y]=estimation(Particules,Config) ;
	s=subplot(3,5,frame,'align');
	I=dessinCroix(I,x,y,0,0,255,8);
	imshow(I)
	title(strcat('Frame ',num2str(frame)));
	
