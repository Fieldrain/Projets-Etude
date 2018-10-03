Img = imread('Demosaic_4.bmp');

CFA = bayer(Img);

figure ,imshow(CFA);

%Img_D = IntBi(CFA);

%Img_D = IntBiMask(CFA);

Img_D = IntConstTeinte(CFA);

figure ,imshow(Img_D);