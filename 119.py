def digitalsum(s):
	res = 0
	for x in s:
		res += int(x)
	return res

print(digitalsum("134"))

upper = 100000000000000000

ans = []

for i in range(2, 1000):
	for j in range(2, 30):
		if i**j > upper:
			break
		if digitalsum(str(i**j)) == i:
#			print(i**j)
			ans.append(i**j)
			
ans.sort()

print(ans[29])