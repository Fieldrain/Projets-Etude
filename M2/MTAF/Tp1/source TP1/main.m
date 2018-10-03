Ft1 = imread('test1.png');
Ft2 = imread('test2.png');

diff = Ft1-Ft2;

%imshow(diff);

[moyenne,deplacement] = deplacementMoyen(Ft1,Ft2);

disp(moyenne);

figure(1),imshow(cat(2,Ft1,Ft2));

[n,m] = size(deplacement);
[p,l] = size(Ft1);

for i=1:n
    for j=1:m
        val = cell2mat(deplacement(i,j));
        startRY = (i-1)*8;
        startRX = (j-1)*8;
        
        endRX = (l+(val(2)-1)*8);
        endRY = ((val(1)-1)*8);
        
        if(startRX == 0)
            startRX = 1;
        end
        
        if(startRY == 0)
            startRY = 1;
        end
        
        if(endRX == 0)
            endRX = l;
        end
        
        if(endRY == 0)
            endRY = 1;
        end
        
        y = [startRY endRY];
        x = [startRX endRX];
        
        lineC = line(x,y);
        lineC.Marker = '>';
        
        rectBase = rectangle('Position',[startRX startRY 8 8]);
        
        rectArr = rectangle('Position',[endRX endRY 8 8]);
        
        pause(0.10) %in seconds  
        delete(lineC);
        delete(rectBase);
        delete(rectArr);
    end
end

