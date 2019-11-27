import math

def zhi(n):
	if n==2 or n==5:
		return True
	if n%2==0:
		return zhi(n//2)
	if n%5==0:
		return zhi(n//5)
	return False

def is_prime(n):
	if n == 1:
		return False
	for i in range(2, int(math.sqrt(n))+1):
		if n % i == 0:
			return False
	return True

def Length(n):
		L=1
		while(True):
			if (10**L-1)%n==0:
				break
			L+=1
		return L
		
a=[]
for i in range(2,1000):
	if is_prime(i) and i!=2 and i!=5:
		a.append([Length(i),i])
print(a)
	