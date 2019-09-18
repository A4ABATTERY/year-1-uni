import math
num = int(input(''))
r = (num / 2)
while abs(num-(r**2))>0.000000000001:
	r = (r +(num / r)/2)
	print(r)
