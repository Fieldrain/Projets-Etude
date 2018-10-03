function [wx,wy] = OneAtATime( blocFt, blocsFt2 ,x, y)

%initialisation avec bloc meme coordonées
blocCourant = blocFt;
courant = Inf;
wx = x;
wy = y;
horizontal = true;

while(true)
    ancien = courant;
    if(horizontal)
        [ horizontal,wx,wy,courant,blocCourant] = testBlocHorizontal(blocCourant,courant,blocsFt2,wx,wy);
        if(~horizontal)
            [ horizontal,wx,wy,courant,blocCourant] = testBlocVertical(blocCourant,courant,blocsFt2,wx,wy);
        end
    else
        [ horizontal,wx,wy,courant,blocCourant] = testBlocVertical(blocCourant,courant,blocsFt2,wx,wy);
        if(horizontal)
            [ horizontal,wx,wy,courant,blocCourant] = testBlocHorizontal(blocCourant,courant,blocsFt2,wx,wy);
        end
    end
    
    if(courant == ancien)
        break;
    end
end

end

