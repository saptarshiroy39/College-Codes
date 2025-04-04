cat(Tom).
dog(Bruno).
lion(Simba).

mammal(X) :- cat(X).
mammal(X) :- dog(X).
mammal(X) :- lion(X).

mammal(X,Y,Z) :- cat(X),dog(Y),lion(Z).

roar(X) :- lion(X).  
bark(X) :- dog(X).