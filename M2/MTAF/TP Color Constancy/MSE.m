function val = MSE( Input_RGB, Output_RGB )

[n,m,k] = size(Input_RGB);
sum = 0;

for i = 1 :n
    for j = 1 :m
        
        if(i<n && i<m)
            p1 = double(Input_RGB(i,j,:));
            p2 = double(Output_RGB(i,j,:));

            sum = sum + (p2 - p1).^2;
        end
    end
end

v = sum / (m*n*3);

val = v(:,:,1) +  v(:,:,2) +  v(:,:,3);
end

