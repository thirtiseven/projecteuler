ai1 = 1
ai2 = 1
cnt = 0

while 1:
	ai = ai1 + ai2
	ai2 = ai1
	ai1 = ai
	cnt = cnt+1
	if len(str(ai)) >= 1000:
		break
		
print(cnt)