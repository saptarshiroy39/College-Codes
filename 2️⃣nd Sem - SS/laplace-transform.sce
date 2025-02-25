//LAPLACE TRANSFORM

--> t = [0:0.5:20]
--> ft = exp(-0.4*t).*sin(12*t)
--> s = %s
--> numfs = s+0.4
--> denfs = (s+0.4)^2+12^2
--> fs = syslin('c',numfs/denfs)
--> fs1 = csim('impulse',t,fs)
--> disp(fs,'Laplace Transform')