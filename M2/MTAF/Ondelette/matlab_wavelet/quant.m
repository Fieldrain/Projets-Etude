function [ w2,nbValDiff ] = quant( w,m )
w2 = w;
val = [];
absW = abs(w2);
% recherche valeur a mettre a zero
while (m > 0)
    valmin = min(absW(:));
    nbMin = sum(absW(:) == valmin);
    if(m-nbMin > 0)
        m = m - nbMin;
        val = [val;valmin,nbMin];
        absW(absW <= valmin) = 1000;
    else
        val = [val;valmin,m];
        break;
    end  
end

[l,c] = size(w2);
w2 = reshape(w2,1,l*c);
valenlever = val(:,end);
% Supprime les valeurs
for i=1:(l*c)
    value = w2(i);
    [ret,ind] = ismember(abs(value),val(:,1));
    if(ret)
        valenlever(ind) = valenlever(ind) - 1;
        w2(i) = 0;
    end
end
w2 = reshape(w2,l,c);
nbValDiff = size(val(:,1));
end

