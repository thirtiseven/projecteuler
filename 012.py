import math

now = 76576500
ans = 1
for i in range(1, now):
	if (now % i == 0):
		ans = ans+1
	if ans >= 500:
		print(now)
		break