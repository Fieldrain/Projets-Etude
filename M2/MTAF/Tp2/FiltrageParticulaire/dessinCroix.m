function I=dessinCroix(I,x,y,r,g,b,l)
	[w h]=size(I);
	for x2=x-l:x+l
		for y2=y-l:y+l
			if x2>0 && y2>0 && x2<=w && y2<=h
				I(x2,y2,1)=r;
				I(x2,y2,2)=g;
				I(x2,y2,3)=b;
			end
		end
	end
