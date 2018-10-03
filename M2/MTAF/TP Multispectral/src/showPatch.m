function [  ] = showPatch( Image_multispectrale )
[n,m,k] = size(Image_multispectrale);
Img_base = zeros(n,m,3);
Img_base(:,:,1) = Image_multispectrale(:,:,7);
Img_base(:,:,2) = Image_multispectrale(:,:,4);
Img_base(:,:,3) = Image_multispectrale(:,:,1);

D = zeros(24,7);
S = load('CoordPatch.mat');
patch = S.patch;

figure(1),imshow(uint8(Img_base));

for i=1:24
    coord = uint16(patch(i,:));
    rectangle('Position',[coord(3),coord(1),coord(4)-coord(3),coord(2)-coord(1)]);
end

end

