//AMPLITUDE SCALING

--> t = [0:5]
--> y = [3 2 1 0 3 1]
--> subplot(3,1,1)
--> plot(t,y)

--> a = 2
--> y1 = a*y  //scaling
--> subplot(3,1,2)
--> plot(t,y1)

--> b = 3
--> y2 = b+y  //shifting
--> subplot(3,1,3)
--> plot(t,y2)