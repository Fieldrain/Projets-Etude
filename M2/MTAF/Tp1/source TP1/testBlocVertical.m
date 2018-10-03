function [ horizontal,wx,wy,courant,blocCourant ] = testBlocVertical( bloc,courant,blocsFt2,wx,wy )
    [n,m] = size(blocsFt2);
    horizontal = false;
    blocCourant = bloc;
    if(wy - 1 >=1)
        blocHaut = cell2mat(blocsFt2(wx,wy-1));
        haut = immse(bloc,blocHaut);
        if(haut < courant)
            courant = haut;
            wy = wy-1;
            blocCourant = blocHaut;
        else
            horizontal = true;
        end
    end
    if(wy +1 <=n)
        blocBas = cell2mat(blocsFt2(wx,wy+1));
        bas = immse(bloc,blocBas);
        if(bas < courant)
            courant = bas;
            wy = wy+1;
            blocCourant = blocBas;
        else
            horizontal = true;
        end
    else
        horizontal = true;
    end

end

