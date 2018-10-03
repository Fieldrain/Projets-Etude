function RGB_Out = ACE(RGB_In,voisinnageI,voisinnageJ,methode)

[n,m,q] = size(RGB_In);

RGB_Out = RGB_In;

%etape 1
for i=1:n
    for j=1:m
        
        debutI = i-voisinnageI;
        if(debutI < 1)
            debutI = 1;
        end
        
        debutJ = j-voisinnageJ;
        if(debutJ <1)
            debutJ = 1;
        end
        
        finI = i+voisinnageI;
        if(finI > n)
            finI = n;
        end
        
        finJ = j+voisinnageJ;
        if(finJ > m)
            finJ = m;
        end
        if(methode == 0)
			RGB_Out(i,j,:) = R_L(RGB_In(debutI:finI,debutJ:finJ,:),RGB_In(i,j,:),i,j,debutI,debutJ);
		else
			RGB_Out(i,j,:) = R_S(RGB_In(debutI:finI,debutJ:finJ,:),RGB_In(i,j,:),i,j,debutI,debutJ);
		end
    end
end

Rc = RGB_Out;
%etape 2

Mc_R = max(max(max(Rc(:,:,1))));
mc_R = min(min(min(Rc(:,:,1))));

Mc_G = max(max(max(Rc(:,:,2))));
mc_G = min(min(min(Rc(:,:,2))));

Mc_B = max(max(max(Rc(:,:,3))));
mc_B = min(min(min(Rc(:,:,3))));

for i=1:n
    for j=1:m
        
        pente = (255-0)/(Mc_R-mc_R);

        RGB_Out(i,j,1) = round(pente*(Rc(i,j,1)-mc_R));
        
        pente = (255-0)/(Mc_G-mc_G);

        RGB_Out(i,j,2) = round(pente*(Rc(i,j,2)-mc_G));
        
        pente = (255-0)/(Mc_B-mc_B);

        RGB_Out(i,j,3) = round(pente*(Rc(i,j,3)-mc_B));
        
    end
end


