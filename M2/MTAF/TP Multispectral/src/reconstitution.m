function Image_RGB = reconstitution(Image_reflectance)

Lumiere = load('CMF.mat');
XYZ_RVB = inv([0.429 0.343 0.178;0.222 0.7070 0.071;0.0190 0.132 0.939]);

[n,m,k] = size(Image_reflectance);
Image_RGB=zeros(n,m,3);
for i=1:n
    for j=1:m
        r = squeeze(Image_reflectance(i,j,:))';
        Image_RGB(i,j,:) = abs((r*Lumiere.CMF*0.00169)*(XYZ_RVB'));
    end
end


end