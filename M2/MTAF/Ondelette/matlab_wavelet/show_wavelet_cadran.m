function Wjq_out = show_wavelet_cadran(W,Jmin,style,j,q)

% show_wavelet_cadran - plot 2D wavelet transform stored using Mallat's ordering.
%
%   [Wjq =] show_wavelet(W, Jmin, style, j, q);
%
% Parameters:
%   W: wavelet transform image
%   Jmin: minimum scale of the transform.
%   style: 'real', 'abs', 'absinv', 'bw'. Default='real'
%   j: scale (cadran of size 2^j by 2^j)
%   q: cadran number
%
%   Optionnal output: Wjq=extracted cadran image
%
%   q=0 is for phi/phi (only for j=Jmin) => LL
%   q=1 is for phi/psi (on X / on Y) => HL
%   q=2 is for psi/phi (on X / on Y) => LH
%   q=3 is for psi/psi (on X / on Y) => HH

clf
subplot(121)
Wout=show_wavelet(W,Jmin,style,0);
imagesc(Wout);
title('Decomposition');

[Wjq,selx,sely]=get_wavelet_cadran(W,j,q);
x0=min(selx(:)); y0=min(sely(:));
x1=max(selx(:)); y1=max(sely(:));

rectangle('Position', [x0 y0 (x1-x0) (y1-y0)],'EdgeColor',[1 0 0]);

%axis('image');
%return 
subplot(122)
switch (style)
    case 'abs'
        imagesc(abs(Wjq),[0 max(abs(Wjq(:)))]);
    case 'absinv'
        imagesc(-abs(Wjq),[-max(abs(Wjq(:)))]);
    case 'real'
        imagesc(Wjq);
    case 'bw'
        imagesc(double(Wjq>20/255),[0 1]);
    otherwise
        error('unknown style');
end
title(sprintf('Cadran j=%d q=%d',j,q));
%colorbar;

if (nargout>=1)
    Wjq_out=Wjq;
end
