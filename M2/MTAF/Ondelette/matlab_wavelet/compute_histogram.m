function [histo,x] = compute_histogram(M,T, avoid_zeros)

% compute_histogram - compute the (symmetric) histogram of a vector after threshold.
%
% histo = compute_histogram(M,T);
%
%	if hp=max(abs(M)), then histo is of size 2*hp+1,
%	and histo(hp+1) is the probability that thresh_T(M)==0.
%
%   Copyright (c) 2005 Gabriel Peyré

if nargin<2
	T = -1;
end
if nargin<3
    avoid_zeros = 1;
end

if length(T)>1
	% build a cell array of histograms
	histo = {};
	for i=1:length(T)
		histo{end+1} = compute_histogram(M,T(i));
	end
	return;
end

% quantize
if T>0
	[Mw, M] = perform_quantization(M, T);
    M = double(M);
end

% compute histrogram
hp = max(abs(M(:)));
hp = min(double(hp),500);   % avoid too big histogramms
histo = zeros(2*hp+1,1);

x = -hp:hp;
for p = -hp:hp;
    histo(p+hp+1) = length( find(M==p) );
end
% avoid zero value
if avoid_zeros
    I = find(histo==0);
    J = find(histo>0);
    histo(I) = mmin(histo(J))/1e9;
end

% normalize to sum to 1
histo = histo/sum(histo);

function y = mmin(x)
y = min(x(:));