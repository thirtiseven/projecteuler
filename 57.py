import math

up = 3
down = 2
ans = 0
for i in range(1, 1000):
	x = up
	y = down
	x = x - y
#	print("%d %d" % (x, y))
	up = x + 3 * y
	down = x + 2 * y
	x = math.gcd(up, down)
	up = up // x
	down = down // x
	len1 = len(str(up))
	len2 = len(str(down))
	print("%d %d" % (up, down))
	if len1 > len2:
		ans = ans + 1
print(ans)	