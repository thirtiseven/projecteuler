#
##print(2**90)
#
#upper = 100000
#ans = 0
#for j in range(1, upper, 1):
#	x = 2**j
#	y = str(x)
#	y = y[0:3]
##	print(y)
#	if y == '123':
#		print(j - ans)
#		ans = j

print(2**73)		
#print(2**196)
#print(2**289)
#print(2**485)

import math

print(math.log2(196))
print(math.log2(289))
print(math.log2(485))

j, p, count = 0, 1, 0
while (j < 678910):
	p = int(str(p * 2)[:15])
	count += 1
	if (str(p)[:3] == '123'):
		j += 1
		
print(count)