I = double(imread('../images/lena256.png'));

n = log2(size(I,1));

Jmin = n-3;
options = struct('wavelet_type','biorthogonal');
w = perform_wavelet_transform(I,Jmin,+1,options);

Ir = perform_wavelet_transform(w,Jmin,-1,options);
% disp(strcat((['Error |I-Ir|/|I| = ' num2str(norm(I(:)-Ir(:))/norm(I(:)))])));

% w2 = zeros(128,128);
% Jmin = 3;
% options = struct('wavelet_type','haar');
% w2(70,7) = 255;
% Ir2 = perform_wavelet_transform(w2,Jmin,-1,options);
% 
% subplot 121;show_wavelet(w2,Jmin,'real',1);colormap('gray');
% subplot 122;imagesc(Ir2);

% disp(strcat(['Energie du signal     = ' num2str(norm(I(:)).^2)]));
% disp(strcat(['Energie des coefficients = ' num2str(norm(w(:)).^2)]));
% 
% T = 100;
% w2 = w(1:end,1:end) .* (abs(w(1:end,1:end)) > T);
% Ir = perform_wavelet_transform(w,Jmin,-1,options);
% Ir2 = perform_wavelet_transform(w2,Jmin,-1,options);
% subplot 121;show_wavelet(w2,Jmin,'real',1);colormap('gray');
% subplot 122;imagesc(Ir2);
% disp(psnr(Ir2,Ir));
 
% [w2,valDiff] = quant(w,0.2*256^2);
% 
% Ir = perform_wavelet_transform(w,Jmin,-1,options);
% Ir2 = perform_wavelet_transform(w2,Jmin,-1,options);
% subplot 121;show_wavelet(w2,Jmin,'real',1);colormap('gray');
% subplot 122;imagesc(Ir2);
% disp(psnr(Ir2,Ir));

% figure(1),
% subplot 121;show_wavelet(w2,Jmin,'real',1);colormap('gray');

% subplot 122;imagesc(Ir2);
% figure(2),
% subplot 121;show_wavelet(w,Jmin,'real',1);colormap('gray');
% subplot 122;imagesc(Ir);
% 
% disp(psnr(Ir2,Ir));

% X = [-10:0.01:10];
% T = 2.0;
% [xhat, k ] = perform_quantization(X,T,1);
% 
% x2 = perform_quantization(k,T,-1);
% 
% E = abs(xhat-X);
% figure(1),
% subplot 151;plot(X);
% subplot 152;plot(xhat);
% subplot 153;plot(X,k);
% subplot 154;plot(X,E);
% subplot 155;plot(x2);

T = 100;
[w_quant,w_k] = perform_quantization(w,T,1);
Ir_quant = perform_wavelet_transform(w_quant,Jmin,-1,options);
subplot 121;show_wavelet(w_quant,Jmin,'real',1);colormap('gray');
subplot 122;imagesc(Ir_quant);
disp(psnr(Ir,Ir_quant));

% [w_quant,w_k] = perform_quantization(w,T,1);
% subplot 141;show_wavelet(w_quant,Jmin,'real',1);colormap('gray');
% subplot 142;imagesc(I);
% Ir_quant = perform_wavelet_transform(w_quant,Jmin,-1,options);
% subplot 143;imagesc(Ir_quant);
% subplot 144;imagesc(Ir_quant-I);
% 
% disp(norm(I(:)-Ir_quant(:)));
% disp(psnr(I,Ir_quant));

% val_psnr = zeros(256);
%   
% for T=1:256
%     [w_quant,w_k] = perform_quantization(w,T,1);
%     Ir_quant = perform_wavelet_transform(w_quant,Jmin,-1,options);
%     val_psnr(T) = psnr(I,Ir_quant);
% end
% 
% figure(1),plot([1:256],val_psnr);

% T = 5;
% [w_quant,w_k] = perform_quantization(w,T,1);
% 
% [hI, bins_I] = integerhist(w_k(:));
% bar(bins_I,hI);
% 
% [HI,HI_pix] = integerentropy(w_k(:));
% 
% disp(strcat((['Error |I-Ir|/|I| = ' num2str(mean(I(:)-w_k(:)))])));
% 
% [y,nbits] = perform_arithmetic_coding(w_k(:),1);
% nbits_pix = nbits / length(w_k(:));

% val_psnr = zeros(256);
% val_bitPixel = zeros(256);
% val_erreur = zeros(256);
% 
% for T=1:256
%     [w_quant,w_k] = perform_quantization(w,T,1);
%     val_erreur(T) = mean(I(:)-w_k(:));
% end
% figure(1),
% plot([1:256],val_erreur);
