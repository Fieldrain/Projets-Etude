function [ value ] = GFC( Rm,Rr )

sum1 = 0;
sum2 = 0;
for j=1:31
    sum1 = sum1 + Rm(j)*Rr(j);
    sum2 = sum2 + pow2(Rm(j))*pow2(Rr(j));
end

value = sum1 / sqrt(sum2);

end

