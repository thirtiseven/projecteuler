import math
def gao(n):
	m = int(math.sqrt(n))
	if m * m == n:
		return 0
	dic = {}
	d = m
	a = n
	b = -m
	c = 1
	len = 0
	while True:
		nc =  a - b * b
		nc /= c
		nd = int((math.sqrt(a) - b) / nc)
		nb = -b - nd * nc
		t = (nb, nc, nd)
		b = nb
		c = nc
		d = nd
		if not t in dic:
			len += 1
			dic[t] = 1
		else:
			break
			
	return len
	
ans = 0
for i in range(1, 10001):
	k = gao(i)
	if k % 2 != 0:
		ans += 1
print(ans)

