//TIME FOLDING - SCALING - SHIFTING OF A SIGNAL

--> t = [0:5]
--> y = [1 3 2 4 1]
--> subplot(4,1,1)
--> plot(t,y)

--> subplot(4,1,2)
--> plot(-t,y)  //folding

--> subplot(4,1,3)
--> plot(2*t,y)  //scaling

--> subplot(4,1,4)
--> plot(t+3,y)  //shifting