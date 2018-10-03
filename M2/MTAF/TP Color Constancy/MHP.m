function RGB_Out = MHP(RGB_In , h1, h2, seuil_couleur_gray, seuil_couleur_wp)

I = (RGB_In(:,:,1) + RGB_In(:,:,2) + RGB_In(:,:,3)) / 3;

%gray
Moy_R = mean(mean(RGB_In(:,:,1)));
Moy_G = mean(mean(RGB_In(:,:,2)));
Moy_B = mean(mean(RGB_In(:,:,3)));

Kr_g = (seuil_couleur_gray(1)/Moy_R);
Kg_g = (seuil_couleur_gray(2)/Moy_G);
Kb_g = (seuil_couleur_gray(3)/Moy_B);

Img_gray(:,:,1) = RGB_In(:,:,1) * Kr_g;
Img_gray(:,:,2) = RGB_In(:,:,2) * Kg_g;
Img_gray(:,:,3) = RGB_In(:,:,3) * Kb_g;

%white_patch
Image_R = RGB_In(:,:,1);
Image_R(I<h1) = [];

Image_G = RGB_In(:,:,2);
Image_G(I<h1) = [];

Image_B = RGB_In(:,:,3);
Image_B(I<h1) = [];

Moy_R_wp = mean(mean(Image_R));
Moy_G_wp = mean(mean(Image_G));
Moy_B_wp = mean(mean(Image_B));

Kr_wp = (seuil_couleur_wp(1)/Moy_R_wp);
Kg_wp = (seuil_couleur_wp(2)/Moy_G_wp);
Kb_wp = (seuil_couleur_wp(3)/Moy_B_wp);

Img_white_patch(:,:,1) = RGB_In(:,:,1) * Kr_wp;
Img_white_patch(:,:,2) = RGB_In(:,:,2) * Kg_wp;
Img_white_patch(:,:,3) = RGB_In(:,:,3) * Kb_wp;

%mix
[n,m] = size(I);
mix = zeros(n,m,3);

for i = 1: n
    for j = 1:m
        
        d = (I(i,j) - h2) / (h1-h2);
        
        Kr_mix = (1-d) * Kr_g + d * Kr_wp;
        Kg_mix = (1-d) * Kg_g + d * Kg_wp;
        Kb_mix = (1-d) * Kb_g + d * Kb_wp;
        
        mix(i,j,1) = RGB_In(i,j,1) * Kr_mix;
        mix(i,j,2) = RGB_In(i,j,2) * Kg_mix;
        mix(i,j,3) = RGB_In(i,j,3) * Kb_mix;
    end
end

Img_mix(:,:,1) = (I(:,:)<h1) .* (I(:,:)>h2) .* mix(:,:,1);
Img_mix(:,:,2) = (I(:,:)<h1) .* (I(:,:)>h2) .* mix(:,:,2);
Img_mix(:,:,3) = (I(:,:)<h1) .* (I(:,:)>h2) .* mix(:,:,3);

RGB_Out(:,:,1) = (I(:,:)>=h1) .* Img_white_patch(:,:,1) + (I(:,:)<=h2) .* Img_gray(:,:,1) + Img_mix(:,:,1); 
RGB_Out(:,:,2) = (I(:,:)>=h1) .* Img_white_patch(:,:,2) + (I(:,:)<=h2) .* Img_gray(:,:,2) + Img_mix(:,:,2); 
RGB_Out(:,:,3) = (I(:,:)>=h1) .* Img_white_patch(:,:,3) + (I(:,:)<=h2) .* Img_gray(:,:,3) + Img_mix(:,:,3); 


