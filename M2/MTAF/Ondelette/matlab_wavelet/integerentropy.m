function [H, Hpix] = integerentropy(x);
% Computes entropy of integer valued vector x(:)
%
% H = integerentropy(x)
%   Compute overall entropy
%
% [H,Hpix] = integerentropy(x)
%   Compute pixelwise entropy Hpix = H / nb_samples

x=round(x(:));
N=length(x);

if (max(x)==min(x))
    H = 0;
else
    % calcul de l'histogramme normalisé
    h = hist(x,min(x):max(x));
    h = h/sum(h);
    
    % Calcul de l'entropie totale en sommant les contributions
    % des valeurs qui apparaissent au moins une fois
    ids=find(h);
    H = -sum(h(ids).*log2(h(ids))) * N; 
end

if (nargout>=2)
    Hpix = H/N;
end
