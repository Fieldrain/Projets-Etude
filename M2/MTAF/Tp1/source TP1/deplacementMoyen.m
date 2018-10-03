function [ moyenne,deplacement ] = deplacementMoyen( Ft1,Ft2 )

blocsFt1 = Split(Ft1,8);
blocsFt2 = Split(Ft2,8);

[n,m] = size(blocsFt1);
moyenne = 0;
deplacement = cell(n,m);

for i = 1 :n
    for j = 1 :m
        blocFt1 = cell2mat(blocsFt1(i,j));
        [x,y] = OneAtATime(blocFt1,blocsFt2,i,j);
        deplacement(i,j) = {[x,y]};
        moyenne = moyenne + x-i + y-j;
    end
end

moyenne = moyenne / i*j;

end

