function RGB_Out = White_patch(RGB_In , seuil)

Max_R = max(max(RGB_In(:,:,1)));
Max_G = max(max(RGB_In(:,:,2)));
Max_B = max(max(RGB_In(:,:,3)));

Seuil_R = seuil(1);
Seuil_G = seuil(2);
Seuil_B = seuil(3);

RGB_Out(:,:,1) = RGB_In(:,:,1) * (Seuil_R/Max_R);
RGB_Out(:,:,2) = RGB_In(:,:,2) * (Seuil_G/Max_G);
RGB_Out(:,:,3) = RGB_In(:,:,3) * (Seuil_B/Max_B);