function [ Output_RGB ] = IntBiMask( Image_CFA )
[m,n] = size(Image_CFA);

Output_RGB = zeros(m,n,3);

Output_RGB(1:2:m,1:2:n,1) = Image_CFA(1:2:m,1:2:n);
Output_RGB(1:2:m,2:2:n,2) = Image_CFA(1:2:m,2:2:n);
Output_RGB(2:2:m,1:2:n,2) = Image_CFA(2:2:m,1:2:n);
Output_RGB(2:2:m,2:2:n,3) = Image_CFA(2:2:m,2:2:n);

MaskVert = [0,1/4,0;
            1/4,0,1/4;
            0,1/4,0];

MaskBleuRouge_1 = [0,1/2,0;
                   0,0,0;
                   0,1/2,0];
          
MaskBleuRouge_2 = [0,0,0;
                   1/2,0,1/2;
                   0,0,0];

MaskBleuRouge_3 = [1/4,0,1/4;
                   0,0,0;
                   1/4,0,1/4];
   
Output_RGB(:,:,1) = Output_RGB(:,:,1) + imfilter(Output_RGB(:,:,1),MaskBleuRouge_1) + imfilter(Output_RGB(:,:,1),MaskBleuRouge_2) + imfilter(Output_RGB(:,:,1),MaskBleuRouge_3);

Output_RGB(:,:,2) = Output_RGB(:,:,2) + imfilter(Output_RGB(:,:,2),MaskVert);

Output_RGB(:,:,3) = Output_RGB(:,:,3) + imfilter(Output_RGB(:,:,3),MaskBleuRouge_1) + imfilter(Output_RGB(:,:,3),MaskBleuRouge_2) + imfilter(Output_RGB(:,:,3),MaskBleuRouge_3);



