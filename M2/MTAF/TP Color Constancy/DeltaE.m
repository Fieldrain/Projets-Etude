function val = DeltaE( Input_RGB, Output_RGB )

[n,m,k] = size(Input_RGB);
sum = 0;

Input_Lab = rgb2lab(double(Input_RGB));
Output_Lab = rgb2lab(double(Output_RGB));


for i = 1 :n
    for j = 1 :m
        if(i<n && i<m)
            d = (Output_Lab(i,j,1)-Input_Lab(i,j,1))^2 +  (Output_Lab(i,j,2)-Input_Lab(i,j,2))^2 + (Output_Lab(i,j,3)-Input_Lab(i,j,3))^2;
            sum = sum + sqrt(d);
        end
    end
end

val = sum / (m*n*3);
end

