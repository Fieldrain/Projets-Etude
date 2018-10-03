function Image_reflectance = interpolation(Image_multispectrale)
[n,m,k] = size(Image_multispectrale);
Image_reflectance = zeros(n,m,31);

for i=1:n
    for j=1:m
        Image_reflectance(i,j,:) = interp1([400:50:700],double(squeeze(Image_multispectrale(i,j,:))),[400:10:700],'spline');
    end
end

end