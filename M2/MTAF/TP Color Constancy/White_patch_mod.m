function RGB_Out = White_patch_mod(RGB_In , seuil , seuil_couleur)

Image_R = RGB_In(:,:,1);
Image_R(Image_R<seuil) = [];

Image_G = RGB_In(:,:,2);
Image_G(Image_G<seuil) = [];

Image_B = RGB_In(:,:,3);
Image_B(Image_B<seuil) = [];

Moy_R = mean(mean(Image_R));
Moy_G = mean(mean(Image_G));
Moy_B = mean(mean(Image_B));

Seuil_R = seuil_couleur(1);
Seuil_G = seuil_couleur(2);
Seuil_B = seuil_couleur(3);

RGB_Out(:,:,1) = RGB_In(:,:,1) * (Seuil_R/Moy_R);
RGB_Out(:,:,2) = RGB_In(:,:,2) * (Seuil_G/Moy_G);
RGB_Out(:,:,3) = RGB_In(:,:,3) * (Seuil_B/Moy_B);