Img_multi = load('macbeth_7.mat');
Image_multispectrale = Img_multi.a;
[n,m,k] = size(Image_multispectrale);

% patch = selection(Image_multispectrale);
% showPatch(Image_multispectrale);

% Manip n°1
% Img_reflectanceInt = interpolation(Image_multispectrale);
% save 'Img_reflectanceInt.mat' Img_reflectanceInt;
% 
% Img = zeros(n,m,3);
% Img(:,:,1) = Img_reflectanceInt(:,:,30);
% Img(:,:,2) = Img_reflectanceInt(:,:,15);
% Img(:,:,3) = Img_reflectanceInt(:,:,1);

% Img_base = zeros(n,m,3);
% Img_base(:,:,1) = Img_multi.a(:,:,7);
% Img_base(:,:,2) = Img_multi.a(:,:,4);
% Img_base(:,:,3) = Img_multi.a(:,:,1);
% 
% subplot 121, imshow(uint8(Img_base));subplot 122, imshow(uint8(Img));

% Manip n°2
% Img_reflectanceInv = invers_indirecte(Image_multispectrale);
% save 'Img_reflectanceInv.mat' Img_reflectanceInv;

% Manip n°3
% Img_reflectance1 = load('Img_reflectanceInt.mat');
% Image1 = reconstitution(Img_reflectance1.Img_reflectanceInt);
% 
% Img_reflectance2 = load('Img_reflectanceInv.mat');
% Image2 = reconstitution(Img_reflectance2.Img_reflectanceInv);
% 
% subplot 121, imshow(uint8(Image1*100));subplot 122, imshow(uint8(Image2*15000));

% Manip n°4
% Img_reflectance1 = load('Img_reflectanceInt.mat');
% Img_reflectance2 = load('Img_reflectanceInv.mat');
% Spectro = load('Macbeth_31_24.mat');

% GFC
% for i=1:24
%     [Rm,Rr] = getCourbe(Spectro.Macbeth_31_24,Img_reflectance1.Img_reflectanceInt,i);
%     [Rm2,Rr2] = getCourbe(Spectro.Macbeth_31_24,Img_reflectance2.Img_reflectanceInv,i);
%     
%     subplot 131, plot([400:10:700],Rm); subplot 132,plot([400:10:700],Rr); subplot 133,plot([400:10:700],Rr2);
%     
%     disp(['Patch n°',num2str(i),' GFC : ',num2str(GFC(Rm,Rr)),' GFC2 : ',num2str(GFC(Rm2,Rr2))]);
%     waitforbuttonpress;
% end

Img_base = zeros(n,m,3);
Img_base(:,:,1) = Img_multi.a(:,:,7);
Img_base(:,:,2) = Img_multi.a(:,:,4);
Img_base(:,:,3) = Img_multi.a(:,:,1);

Img_reflectance1 = load('Img_reflectanceInt.mat');
Image1 = reconstitution(Img_reflectance1.Img_reflectanceInt) * 70;

Img_reflectance2 = load('Img_reflectanceInv.mat');
Image2 = reconstitution(Img_reflectance2.Img_reflectanceInv) * 15000;

imwrite(uint8(Img_base),char(strcat('../Resultat/','Multi.jpg')),'jpg','Quality',100);
imwrite(uint8(Image1),char(strcat('../Resultat/','Interpolation.jpg')),'jpg','Quality',100);
imwrite(uint8(Image2),char(strcat('../Resultat/','inverse.jpg')),'jpg','Quality',100);
