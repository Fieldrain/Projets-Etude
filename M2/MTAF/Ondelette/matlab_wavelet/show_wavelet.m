function WM_out = show_wavelet(WM, Jmin, style, edge_color, renormalize)

% show_wavelet - plot 2D wavelet transform stored using Mallat's ordering.
%
%   show_wavelet(WT, Jmin, style [, edge_color , renormalize]);
%
% Parameters:
%   Jmin: minimum scale of the transform
%         (smallest cadran of size 2^Jmin by 2^Jmin).
%   style: 'real', 'abs', 'absinv', 'bw'. Default='real'
%   edge_color: 0 (black) to 1 (white). Default=0.
%   renormalize: ???
%
%   'WT' is the wavelet transform (in Mallat's ordering, not lifting inplace
%       ordering).
%   
%   Copyright (c) 2003 Gabriel Peyré

if nargin<2
    Jmin = 1;
end

if nargin<3 || isempty(style)
    style = 'real';
end

if nargin<4
    edge_color = 0;
end

if nargin<5
    renormalize = 0;
end

n = length(WM);

for j=Jmin:log2(n)-1
    qmin = double(~(j==Jmin));
    for q=qmin:3
        [selx,sely] = compute_quadrant_selection(j,q);
        M1 = WM(selx,sely,:);
        
        if strcmp(style, 'abs')
            M1 = rescale( abs(M1) );

            if renormalize
                M1 = 1.5*M1;
                I = find(abs(M1)>1);
                M1(I) = M1(I)./abs(M1(I));
            end

        elseif strcmp(style, 'absinv')
            
            M1 = rescale(abs(M1));
            if renormalize
                M1 = 2*M1;
                I = find(abs(M1)>1);
                M1(I) = M1(I)./abs(M1(I));
            end

            M1 = rescale( -abs(M1) );
        elseif strcmp(style, 'real')
            M1 = rescale(M1);
        elseif strcmp(style, 'bw')
            M1 = rescale(abs(M1));
            M1 = double( M1<20/255 );
        else
            error('unknown style');    
        end
        
        WM(selx,sely,:) = M1;
    end
    % white borders
    if edge_color>=0
        WM(2^j,1:2^(j+1)) = edge_color; 
        WM(1:2^(j+1),2^j) = edge_color;
    end
end

%axis('image');
%axis('off');

if (nargout>=1)
    WM_out=WM;
else
    imagesc(WM);
end
