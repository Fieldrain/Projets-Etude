function [Wjq,selx_out,sely_out]=get_wavelet_cadran(W,j,q);

% get_wavelet_cadran - get one cadran from Mallat ordering wavelet image
%
%   get_wavelet_cadran(W, Jmin, j, q);
%
% Parameters:
%   W: wavelet transform image
%   j: scale
%   q: cadran number
%
%   q=0 is for phi/phi (only for j=Jmin) => LL
%   q=1 is for phi/psi (on X / on Y) => HL
%   q=2 is for psi/phi (on X / on Y) => LH
%   q=3 is for psi/psi (on X / on Y) => HH

[selx,sely] = compute_quadrant_selection(j,q);
x0=min(selx); y0=min(sely);
x1=max(selx); y1=max(sely);
Wjq=W(sely,selx);

if (nargout>=2)
    selx_out=selx;
end
if (nargout>=3)
    sely_out=sely;
end
