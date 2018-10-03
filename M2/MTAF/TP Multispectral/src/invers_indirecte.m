function Image_reflectance = invers_indirecte(Image_multispectrale)
[n,m,k] = size(Image_multispectrale);
Image_reflectance = zeros(n,m,31);

D = zeros(24,7);
S = load('CoordPatch.mat');
patch = S.patch;

for i=1:24
    coord = uint16(patch(i,:));
    for l=1:k
        r = Image_multispectrale(coord(1):coord(2),coord(3):coord(4),l);
        D(i,l) = mean2(r);
    end

end

R = load('Macbeth_31_24.mat');
Q = mldivide(D,R.Macbeth_31_24);

for i=1:n
    for j=1:m
        Image_reflectance(i,j,:) = double(squeeze(Image_multispectrale(i,j,:))') * Q;
    end
end

end