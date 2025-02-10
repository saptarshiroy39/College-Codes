//CONVOLUTION OF DISCRETE SIGNAL

--> t1 = [0:3]
--> x = [1 3 5 7]
--> subplot(3,1,1)
--> plot2d3 (t1,x)
--> t2 = [0:3]
--> h = [0 2 4 6]
--> subplot(3,1,2)
--> plot2d3 (t2,h)
--> y=convol(x,h)
--> disp(y,'Convolution Operation')
--> l = length(y)
--> t3 = 0:l-1
--> subplot(3,1,3)
--> plot2d3 (t3,y)