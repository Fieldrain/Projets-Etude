function [ patch ] = selection(Image_multispectrale)
[n,m,k] = size(Image_multispectrale);
Img_base = zeros(n,m,3);
Img_base(:,:,1) = Image_multispectrale(:,:,7);
Img_base(:,:,2) = Image_multispectrale(:,:,4);
Img_base(:,:,3) = Image_multispectrale(:,:,1);

patch = zeros(24,4);
figure(1),imshow(uint8(Img_base));

for i=1:24
    disp(['Patch n°',num2str(i)]);
    r = getrect;
    
    x0 =(r(1));
    y0 =(r(2));
    w =(r(3));
    h =(r(4));

    x1 = (x0+w);
    y1 = (y0+h);
    
    patch(i,1) = y0;
    patch(i,2) = y1;
    patch(i,3) = x0;
    patch(i,4) = x1;
end

save 'CoordPatch.mat' patch;

end

