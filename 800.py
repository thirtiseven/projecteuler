import math

print(800800*math.log(800800))
# 10885567.898792105
print(800*math.log(800))

maxn = 100000000

def PrimeInit():
	IsPrime = [True] * maxn
	Prime = []
	for i in range(2, maxn):
		if IsPrime[i]:
			Prime.append(i)
			for j in range(i * i, maxn, i):
				IsPrime[j] = False;
	return Prime

primes = PrimeInit()
ans = 0

for i in range(len(primes)):
    # for j in range(i+1, len(primes)):
    #     q = primes[i]
    #     p = primes[j]
    #     x = p * math.log(q) + q * math.log(p)
    #     if x > 10885567.898792105:
    #         break
    #     ans += 1
    l = i
    r = len(primes) - 1
    while l < r:
        mid = (l + r + 1) // 2
        if primes[mid] * math.log(primes[i]) + primes[i] * math.log(primes[mid]) <= 10885567.898792105:
            l = mid
        else:
            r = mid - 1
    ans += l - i
	
print(ans)