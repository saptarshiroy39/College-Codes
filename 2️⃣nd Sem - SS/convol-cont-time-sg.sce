//CONVOLUTION OF CONTINUOUS-TIME SIGNAL

--> T = 10
--> x = ones(1,T)
--> N1 = 0:length(x)-1
--> h = ones(1,T)
--> N2 = 0:length(h)-1
--> y = conv(x,h)-1
--> N = 0:length(x)+length(h)-2
--> subplot(3,1,1)
--> plot (N1,x)
--> subplot(3,1,2)
--> plot (N2,h)
--> subplot(3,1,3)
--> plot (N,y)