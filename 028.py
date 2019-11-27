#1,3,5,7,9,13,17,21,25
#
#	The following hold:
#	1. a(n) = (2k + 1)^2  when n = 4k + 1, k >= 0
#	2. a(n) = 4*k^2 + 1   when n = 4k - 1, k > 0
#	3  a(n) = k^2 + k + 1 when n = 2k, k > 0.

# a(n) = floor_(n*(n+2)/4) + floor_(n(mod 4)/3) + 1

ans = 0
upper = 1001*1001
i = 0

while True:
	i = i+1
	x = (i*(i+2)//4) + ((i%4)//3) + 1
	if x > upper:
		break
	else:
		ans = ans + x

print(ans)