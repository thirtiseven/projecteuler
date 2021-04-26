from decimal import *
import math

myothercontext = Context(prec=102, rounding = 'ROUND_FLOOR')
setcontext(myothercontext)

def is_sqr(n):
	a = int(math.sqrt(n))
	return a * a == n

ans = 0

for i in range(1, 101):
	if not is_sqr(i):
		x = Decimal(i)
		r = Decimal.sqrt(x)
		print(r)
		strx = str(r)
		tot = 0
		for j in range(0, 101):
			if strx[j] != '.':
				tot += int(strx[j])
		ans += tot
		print(tot)
print(ans)

#2022036