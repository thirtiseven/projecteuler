x = 28433

for i in range(0, 7830457):
	x = x * 2
	x = x % 10000000000

x = x+1

print(x)