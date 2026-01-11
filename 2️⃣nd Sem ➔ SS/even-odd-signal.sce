//EVEN & ODD PART OF A SIGNAL

--> t = [-2:2]
--> n = [1 2 3 1 3]
--> subplot(3,1,1)
--> plot(t,n)
--> c = 3
--> for j=1:length(t)
  > i = t(j)
  > ne(j) = (1/2)*(n(c+i)+n(c-i))
  > no(j) = (1/2)*(n(c+i)-n(c-i))
  > end
--> ne = [ne(c-2),ne(c-1),ne(c+0),ne(c+1),ne(c+2)]
--> no = [no(c-2),no(c-1),no(c+0),no(c+1),no(c+2)]
--> subplot(3,1,2)
--> plot(t,ne)
--> subplot(3,1,3)
--> plot(t,no)