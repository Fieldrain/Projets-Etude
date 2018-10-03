function [h, bins] = integerhist(x, bins);
% Calcul d'histogramme sur une image à valeurs entières
%
% [h, bins] = integerhist(x);
%   Calcule automatiquement les valeurs min et max
%
% [h, bins] = integerhist(x, bins);

x=round(x(:));

if (nargin<2)
    bins=[min(x):max(x)];
end

h=hist(x,bins);

