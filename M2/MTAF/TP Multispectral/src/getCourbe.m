function [ Rm,Rr ] = getCourbe( Spectrophotometre,Image_Reflectance,NumPatch)
Rm = Spectrophotometre(NumPatch,:)';

S = load('CoordPatch.mat');
patch = S.patch;

Rr = zeros(31);
coord = uint16(patch(NumPatch,:));
for l=1:31
    r = Image_Reflectance(coord(1):coord(2),coord(3):coord(4),l);
    Rr(l) = mean2(r);
end


end

