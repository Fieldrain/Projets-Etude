function RGB_Out = Gray(RGB_In)

Moy_R = mean(mean(RGB_In(:,:,1)));
Moy_G = mean(mean(RGB_In(:,:,2)));
Moy_B = mean(mean(RGB_In(:,:,3)));

Avg = (Moy_R + Moy_G + Moy_B ) / 3;

RGB_Out(:,:,1) = RGB_In(:,:,1) * (Avg/Moy_R);
RGB_Out(:,:,2) = RGB_In(:,:,2) * (Avg/Moy_G);
RGB_Out(:,:,3) = RGB_In(:,:,3) * (Avg/Moy_B);