
% LECTURE DE l'IMAGE
I=imread('../images/barbarazoom256.png');
if (size(I,3)>1)
  I=double(rgb2gray(I)); % Conversion en niveaux de gris
else
  I=double(I);
end

% PARAMETRES DE LA DECOMPOSITION
N=size(I,1);  n=log2(N);
Jmax=n-1;
Jmin=n-2;
options=struct('wavelet_type','biorthogonal'); 
%options=struct('wavelet_type','haar'); 

% TRAITEMENT
W=perform_wavelet_transform(I, Jmin, 1, options);
R=perform_wavelet_transform(W, Jmin, -1, options);

% AFFICHAGE
figure(1)
subplot 121
imagesc(I,[0,255]);
colormap(gray(256));
title('Image d''origine');
subplot 122
show_wavelet(W,Jmin,'real');
title('Decomposition en ondelettes');

figure(2)
j=6; q=2;
show_wavelet_cadran(W,Jmin,'real',j,q);
colormap(gray(256));
