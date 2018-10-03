function [ valeur ] = InterpolationDiagonale( Img , i , j )
    [m,n] = size(Img);
    somme = 0;
    nbVal = 0;

    if(i>1 && j>1)
        somme = somme + Img(i-1,j-1);
        nbVal = nbVal + 1;
    end

    if(i>1 && j<n)
        somme = somme + Img(i-1,j+1);
        nbVal = nbVal + 1;
    end

    if(i<m && j>1)
        somme = somme + Img(i+1,j-1);
        nbVal = nbVal + 1;
    end

    if(i<m && j<n)
        somme = somme + Img(i+1,j+1);
        nbVal = nbVal + 1;
    end
    
    valeur = somme/nbVal;