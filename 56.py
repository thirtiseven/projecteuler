def digtalsum(x):
	d = 0
	while x > 0:
		d = d + x % 10
		x = x // 10
	return d
	
	
ans = 0
for i in range(1, 101):
	for j in range(1, 101):
		ans = max(ans, digtalsum(pow(i, j)))
		
print(ans)