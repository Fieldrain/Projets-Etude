function [ img ] = reconstitue( blocs )
[n,m] = size(blocs);

img = {};
for i = 1 :n
    ligne = {};
    for j = 1 :m
        ligne = [ligne,blocs(i,j)];
    end
    
    img = [img;ligne];
end
end

