ans = 0

upper = 51

for x1 in range(0, upper):
	for y1 in range(0, upper):
		for x2 in range(0, upper):
			for y2 in range(0, upper):
				diffx, diffy = x1-x2, y1-y2
				if x1 + y1 == 0 or x2 + y2 == 0:
					continue
				if x1 == x2 and y1 == y2:
					continue
				if x1 * x2 + y1 * y2 == 0 or x1 * diffx + y1 * diffy == 0 or x2 * diffx + y2 * diffy == 0:
#					print("%s %s %s %s" % (x1, y1, x2, y2))
					ans = ans + 1

print(ans/2)
				