function [ result ] = R_L( Pixels, pixel,i,j,debutI,debutJ)
[n,m,f] = size(Pixels);
result = pixel;

for o=1:n
    for k=1:m
        i2 = debutI + o;
        j2 = debutJ + k;
        
        if(i2~=i && j2 ~=j)
            distance = sqrt((i2 - i)^2 + (j2 - j)^2);
			
            p2 = Pixels(o,k,1);
            result(1) = result(1) + (pixel(1)-p2)/distance);
			
            p2 = Pixels(o,k,2);
            result(2) = result(2) + (pixel(2)-p2)/distance);
			
            p2 = Pixels(o,k,3);
            result(3) = result(3) + (pixel(3)-p2)/distance);
        end
    end
end

end

