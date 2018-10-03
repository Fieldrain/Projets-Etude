function [ Image_CFA ] = bayer( Input_RGB )
[m,n,p] = size(Input_RGB);

Image_CFA = Input_RGB(1:m,1:n,2);

for i = 1:m
    for j = 1:n
        
        %pixel bleu
        if (mod(i,2) == 0 && mod(j,2) == 0)
            Image_CFA(i,j) = Input_RGB(i,j,3);
        end
        
        %pixel rouge
        if (mod(i,2) ~= 0 && mod(j,2) ~= 0)
            Image_CFA(i,j) = Input_RGB(i,j,1);
        end
        
    end
end
