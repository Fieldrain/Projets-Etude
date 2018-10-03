function [I] = dwtuncompress(B)
% Décompresse un flux binaire compressé par DWT en image
%
% I = dwtuncompress(B)
%   B: flux binaire sous la forme [n Jmin T y(1:end)]
%   avec 2^n=taille de l'image
%        Jmin: indice du niveau minimum de décomposition DWT
%        T: pas de quantification
%        y: flux compressé correspondant à W
%
% L'ondelette est wavelet_type='biorthogonal', vm=4

% Convertit en double au cas où l'on aurait des uint8 en entrée
B = double(B);

% Information de l'en-tête
n=B(1);
Jmin=B(2);
T=B(3);

% Flux compressé
y=B(4:end);

% Type d'ondelette
options.wavelet_type='biorthogonal';
options.vm=4;

% Chaine de décompression
W_int=perform_arithmetic_coding(y, -1);
W=perform_quantization(double(W_int), T, -1);
W=reshape(W,2^n,2^n);
I=perform_wavelet_transform(W, Jmin, -1, options);
