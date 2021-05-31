def rad(x):
	res = 1
	for i in range(2, x):
		if x % i == 0:
			res *= i
		while x % i == 0:
			x //= i
		if i * i > x:
			break
	if x > 1:
		res *= x
	return res

rads = []

for i in range(1, 100001):
#	print("%s %s" % (i, rad(i)))
	rads.append(rad(i))
	
radspair = zip(rads, [i for i in range(1, 100001)])

sorted_radspair = sorted(radspair)

print(sorted_radspair[9999])