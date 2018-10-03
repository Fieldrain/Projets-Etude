function [ n,Jmin,T,y ] = dwtcompress( image )

n = log2(size(image,1));
Jmin = n-3;
T = 10;

options = struct('wavelet_type','biorthogonal');
w = perform_wavelet_transform(image,Jmin,+1,options);
[w_quant,w_k] = perform_quantization(w,T,1);
[y,nbits] = perform_arithmetic_coding(w_k(:),1);

end

