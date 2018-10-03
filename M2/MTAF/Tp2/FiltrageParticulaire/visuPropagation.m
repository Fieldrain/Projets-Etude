function visuPropagation(ParticulesAv,ParticulesAp,Config,I,frame)
	figure;
	imshow(I) ;
	hold on;
	for k=1:Config.nombre_de_particule
		plot([ParticulesAv(k,1) ParticulesAp(k,1)],[ParticulesAv(k,2) ParticulesAp(k,2)],'Color','r','LineWidth',2)
	end
	hold off;
	
