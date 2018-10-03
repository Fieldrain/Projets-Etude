function [blocs] = Split( img ,pas)
[n,m] = size(img);
blocs = cell(n/pas,m/pas);
x=1;
for i = 1:pas:n-(pas-1)
    y=1;
    for j = 1:pas:m-(pas-1)
        blocs(x,y) = {img(i:i+(pas-1),j:j+(pas-1))};
        y= y+1;
    end
    x = x+1;
end

end

