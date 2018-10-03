function [ result ] = R_S( Pixels, pixel,i,j,debutI,debutJ)
[n,m,f] = size(Pixels);
result = pixel;

for o=1:n
    for k=1:m
        i2 = debutI + o;
        j2 = debutJ + k;
        
        if(i2~=i && j2 ~=j)
            p2 = Pixels(o,k,1);
            distance = sqrt((i2 - i)^2 + (j2 - j)^2);
            
            if((pixel(1)-p2)<0)
                result(1) = result(1) + (0);
            else
                result(1) = result(1) + 100/distance;
            end
            
            p2 = Pixels(o,k,2);
            
            if((pixel(2)-p2)<0)
                result(2) = result(2) + (0);
            else
                result(2) = result(2) + 100/distance;
            end
            
            p2 = Pixels(o,k,3);
            
            if((pixel(3)-p2)<0)
                result(3) = result(3) + (0);
            else
                result(3) = result(3) + 100/distance;
            end
        end
    end
end

end

