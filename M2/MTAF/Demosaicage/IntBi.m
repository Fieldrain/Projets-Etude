function [ Output_RGB ] = IntBi( Image_CFA )

[m,n] = size(Image_CFA);
Output_RGB = zeros(m,n,3);

for i = 1:m
    for j= 1:n

        %pixel bleu
        if (mod(i,2) == 0 && mod(j,2) == 0)
            %calcule pixel rouge
            Output_RGB(i,j,1) = InterpolationDiagonale(Image_CFA, i, j);
            
            %calcule pixel vert
            Output_RGB(i,j,2) = InterpolationVert(Image_CFA, i, j);
            
            %recupere valeur pixel bleu
            Output_RGB(i,j,3) = Image_CFA(i,j);
        else
            %pixel rouge
            if (mod(i,2) ~= 0 && mod(j,2) ~= 0)
                %recupere valeur pixel rouge
                Output_RGB(i,j,1) = Image_CFA(i,j);

                %calcule pixel vert
                Output_RGB(i,j,2) = InterpolationVert(Image_CFA, i, j);

                %calcule pixel bleu
                Output_RGB(i,j,3) = InterpolationDiagonale(Image_CFA, i, j);

            % pixel vert
            else
                % ligne rouge
                if(mod(i,2) ~= 0)
                    %calcule pixel rouge
                    Output_RGB(i,j,1) = InterpolationHorizontale(Image_CFA, i, j);

                    %calcule pixel bleu
                    Output_RGB(i,j,3) = InterpolationVerticale(Image_CFA, i, j);
                else
                    %calcule pixel rouge
                    Output_RGB(i,j,1) = InterpolationVerticale(Image_CFA, i, j);

                    %calcule pixel bleu
                    Output_RGB(i,j,3) = InterpolationHorizontale(Image_CFA, i, j);
                end

                %recupere valeur pixel vert
                Output_RGB(i,j,2) = Image_CFA(i,j);
            end
        end 
    end
end