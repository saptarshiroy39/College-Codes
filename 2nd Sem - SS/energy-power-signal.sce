//ENERGY & POWER OF A SIGNAL

--> t = [0:0.001:10]
--> y = 5*exp(-5*t)
--> E = integrate('(5*exp(-5*t))^2','t',0,2*%pi)
--> disp (E,'Energy of the signal in Joule')

--> t = [0:0.001:10]
--> y = 5*exp(-5*t)
--> P = integrate('(5*exp(-5*t))^2','t',0,2*%pi)/(2*%pi)
--> disp (P,'Power of the signal in Watt')