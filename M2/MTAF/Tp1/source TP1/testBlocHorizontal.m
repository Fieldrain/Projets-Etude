function [ horizontal,wx,wy,courant,blocCourant] = testBlocHorizontal( bloc,courant,blocsFt2,wx,wy)
    [n,m] = size(blocsFt2);
    horizontal = true;
    blocCourant = bloc;
    if(wx - 1 >=1)
        blocGauche = cell2mat(blocsFt2(wx-1,wy));
        gauche = immse(bloc,blocGauche);
        if(gauche < courant)
            courant = gauche;
            wx = wx-1;
            blocCourant = blocGauche;
        else
            horizontal = false;
        end
    end
    if(wx +1 <=n)
        blocDroite = cell2mat(blocsFt2(wx+1,wy));
        droite = immse(bloc,blocDroite);
        if(droite < courant)
            courant = droite;
            wx = wx+1;
            blocCourant = blocDroite;
        else
            horizontal = false;
        end
    else
        horizontal = false;
    end
end

