function [ valeur ] = InterpolationVerticale( Img ,i , j )
    [m,n] = size(Img);
    somme = 0;
    nbVal = 0;

    if(i>1)
        somme = somme + Img(i-1,j);
        nbVal = nbVal + 1;
    end

    if(i<m)
        somme = somme + Img(i+1,j);
        nbVal = nbVal + 1;
    end
    
    valeur = somme /nbVal;
