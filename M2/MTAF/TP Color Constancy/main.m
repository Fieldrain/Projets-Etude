%Img = double(imread('Test1/building.jpg'));
%figure(1),imshow(uint8(Img));
%figure(2),imshow(uint8(Gray(Img)));
%figure(3),imshow(uint8(White_patch(Img , [255,255,255])));
%figure(4),imshow(uint8(White_patch_mod(Img , 100 , [255,255,255])));
%figure(5),imshow(uint8(MHP(Img , 200 , 100, [255,255,255], [255,255,255])));
%figure(6),imshow(uint8(ACE(Img,m,n)));

fichiers = ["building","Film","fish","HP_Jouets_1","HP_Jouets_2","HP_Jouets_3","HP_Jouets_4","HP_Jouets_5","HP-Macbeth_1","HP-Macbeth_2","Nature","Notredam_1"];
extensions = [".jpg",".tif",".tif",".jpg",".jpg",".jpg",".jpg",".jpg",".jpg",".jpg",".tif",".jpg"];

fichiers2 = ["Bureau","feille_cerise","feuille","green_frog","Table"];
extensions2 = [".png",".jpg",".tif",".jpg",".png"];

methodes = ["Gray","WP","WP_Mod","MHP","ACE_L","ACE_S"];

[p,s] = size(fichiers);
[m,t] = size(methodes);

disp("Fichier Test1");
for i=1:s
    fichier = fichiers(i);
    extension = extensions(i);
    
    Img = double(imread(char(strcat('Test1/',fichier,extension))));

    Img_D = Img;

    for j=1:t
        methode = methodes(j);
        switch (methode)
            case char('Gray')
                Img_D = uint8(Gray(Img));
            case char('WP')
                Img_D = uint8(White_patch(Img , [255,255,255]));
            case char('WP_Mod')
                Img_D = uint8(White_patch_mod(Img , 100 , [255,255,255]));
            case char('MHP')
                Img_D = uint8(MHP(Img , 200 , 100, [255,255,255], [255,255,255]));
            case char('ACE_L')
                Img_D = uint8(ACE(Img,20,20,0));
			case char('ACE_S')
                Img_D = uint8(ACE(Img,20,20,1));
        end

        imwrite(Img_D,char(strcat('Test1/Resultat/',fichier,'_',methode,'.jpg')),'jpg','Quality',100);
    end
end

disp("Fichier Test2");

for i=1:s
    fichier = fichiers2(i);
    extension = extensions2(i);
    
    Img = double(imread(char(strcat('Test2/',fichier,extension))));

    Img_D = Img;

    for j=1:t
        methode = methodes(j);
        switch (methode)
            case char('Gray')
                Img_D = uint8(Gray(Img));
            case char('WP')
                Img_D = uint8(White_patch(Img , [255,255,255]));
            case char('WP_Mod')
                Img_D = uint8(White_patch_mod(Img , 100 , [255,255,255]));
            case char('MHP')
                Img_D = uint8(MHP(Img , 200 , 100, [255,255,255], [255,255,255]));
            case char('ACE_L')
                Img_D = uint8(ACE(Img,20,20,0));
			case char('ACE_S')
                Img_D = uint8(ACE(Img,20,20,1));
        end

        imwrite(Img_D,char(strcat('Test2/Resultat/',fichier,'_',methode,'.jpg')),'jpg','Quality',100);
    end
end