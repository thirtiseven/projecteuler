ans = 0
for i in range(1, 1000000):
	now = 0
	for j in str(i):
		x = int(j)
		now = now + x*x*x*x*x
	if now == i:
		ans = ans+now
		print(now)
print(ans)

#443840