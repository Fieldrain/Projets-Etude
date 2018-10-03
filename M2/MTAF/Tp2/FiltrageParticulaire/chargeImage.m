function I=chargeImage(Config,frame)
	nom=strcat('sequence/',Config.nom_sequence,num2str(frame),'.png');
	I=imread(char(nom)) ;
