from math import *

def euclid_algo(x, y, verbose=True):
	if x < y: # We want x >= y
		return euclid_algo(y, x, verbose)
	print()
	while y != 0:
		if verbose: print('%s = %s * %s + %s' % (x, floor(x/y), y, x % y))
		(x, y) = (y, x % y)
	
	if verbose: print('gcd is %s' % x) 
	return x

def lcm(x, y):  
	if x > y:  
		greater = x  
	else:  
		greater = y  
	while(True):		
		if((greater % x == 0) and (greater % y == 0)):  
			lcm = greater  
			break
		greater += 1  
	return lcm

euclid_algo(63792, 725)
# print ('mmc = ', lcm(24, 3))