function [I] = dwtuncompress(B)
% D�compresse un flux binaire compress� par DWT en image
%
% I = dwtuncompress(B)
%   B: flux binaire sous la forme [n Jmin T y(1:end)]
%   avec 2^n=taille de l'image
%        Jmin: indice du niveau minimum de d�composition DWT
%        T: pas de quantification
%        y: flux compress� correspondant � W
%
% L'ondelette est wavelet_type='biorthogonal', vm=4

% Convertit en double au cas o� l'on aurait des uint8 en entr�e
B = double(B);

% Information de l'en-t�te
n=B(1);
Jmin=B(2);
T=B(3);

% Flux compress�
y=B(4:end);

% Type d'ondelette
options.wavelet_type='biorthogonal';
options.vm=4;

% Chaine de d�compression
W_int=perform_arithmetic_coding(y, -1);
W=perform_quantization(double(W_int), T, -1);
W=reshape(W,2^n,2^n);
I=perform_wavelet_transform(W, Jmin, -1, options);
