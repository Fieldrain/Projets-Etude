function [ Output_RGB ] = IntConsTeinte( Image_CFA )

[m,n] = size(Image_CFA);
Output_RGB = zeros(m,n,3);

Output_RGB(1:2:m,1:2:n,1) = Image_CFA(1:2:m,1:2:n);
%ligne rouge
Output_RGB(1:2:m,2:2:n,2) = Image_CFA(1:2:m,2:2:n);
%ligne bleu
Output_RGB(2:2:m,1:2:n,2) = Image_CFA(2:2:m,1:2:n);
Output_RGB(2:2:m,2:2:n,3) = Image_CFA(2:2:m,2:2:n);

MaskVert = [0,1/4,0;
            1/4,0,1/4;
            0,1/4,0];
        
Output_RGB(:,:,2) = Output_RGB(:,:,2) + imfilter(Output_RGB(:,:,2),MaskVert);

%Output_RGB(2:2:m,1:2:n,3) = Image_CFA(2:2:m,1:2:n) / 2 * (Image_CFA(2:2:m,2:2:n-2) + Image_CFA(2:2:m,4:2:n) / Output_RGB(2:2:m,2:2:n-2,2) + Output_RGB(2:2:m,4:2:n,2));
%Output_RGB(1:2:m,2:2:n,3) = Image_CFA(1:2:m,2:2:n) / 2 * (Image_CFA(2:2:m-2,2:2:n) + Image_CFA(4:2:m,2:2:n) / Output_RGB(2:2:m-2,2:2:n,2) + Output_RGB(4:2:m,2:2:n,2));
%Output_RGB(3:2:m-2,3:2:n-2,3) = Output_RGB(3:2:m-2,3:2:n-2,2) / 4 * ((Image_CFA(2:2:m-2,1:2:n-2) + Image_CFA(2:2:m-2,4:2:n) + Image_CFA(4:2:m,1:2:n-2) + Image_CFA(4:2:m,4:2:n)) / ((Output_RGB(2:2:m-2,1:2:n-2,2) + Output_RGB(2:2:m-2,4:2:n,2) + Output_RGB(4:2:m,1:2:n-2,2) + Output_RGB(4:2:m,4:2:n,2)));

%Output_RGB(2:2:m,1:2:n,1) = Image_CFA(2:2:m,1:2:n) / 2 * ();
%Output_RGB(1:2:m,2:2:n,1) = Image_CFA(1:2:m,2:2:n) / 2 * ();
%Output_RGB(2:2:m-1,2:2:n-1,1) = Output_RGB(1:2:m,3:2:n,2) / 4 * ();