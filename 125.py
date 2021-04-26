def is_palindromic(s):
	ss = s[::-1]
	return s == ss

inf = 100000000

upper = 100004

ans = 0

for start in range(1, upper):
	cur = 0
	yes = 0
	for i in range(start, upper):
		if cur > 0:
			yes = 1
		cur += i * i
		if cur >= inf:
			break
		if yes and is_palindromic(str(cur)):
			ans += cur
print(ans)

#2906969179