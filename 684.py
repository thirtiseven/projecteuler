mod = 1000000007

def PowMod(a, b):
	a %= mod
	ans = 1 
	while b > 0: 
		if (b & 1) > 0:
			ans = (ans * a) % mod  
		a = (a * a) % mod
		b >>= 1
	return ans 


def S(a):
	rmd = a%9
	quo = a//9
	res = 0
	res = 6*(PowMod(10, quo)-1)-9*quo
	print('.')
	res %= mod
	tmp = 0
	for i in range(1, rmd+1):
		tmp += i
	print('.')
	xx = PowMod(10, quo)
	xx %= mod
	print('.')
	res += tmp*(xx)+rmd*(xx-1)
	res %= mod
	print('.')
	return res
	
print(S(20))
	
a = [0, 1]
for i in range(2, 91):
	a.append((a[i-1]+a[i-2]))

ans = 0

for i in range(2, 91):
	ans += S(a[i])
	ans %= mod
	print(a[i], i, ans)
	
print(ans)
