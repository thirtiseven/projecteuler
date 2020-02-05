import fractions

x = [0]
cnt = 1
for i in range(1, 101):
	if i % 3 == 2:
		x.append(cnt*2)
		cnt += 1
	else:
		x.append(1)

upper = 99
ans = fractions.Fraction(1, x[upper])
for i in range(upper-1, 0, -1):
	ans = fractions.Fraction(1, 1) / (fractions.Fraction(x[i], 1) + ans)
ans = ans + fractions.Fraction(2, 1)

print(ans)

def digitalsum(x):
	res = 0
	while x > 0:
		res += x%10
		x //= 10
	return res
	
print(digitalsum(6963524437876961749120273824619538346438023188214475670667))