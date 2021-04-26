

def roman_to_int(s):
    rom_val = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    int_val = 0
    for i in range(len(s)):
        if i > 0 and rom_val[s[i]] > rom_val[s[i - 1]]:
            int_val += rom_val[s[i]] - 2 * rom_val[s[i - 1]]
        else:
            int_val += rom_val[s[i]]
    return int_val

ans = 0

#print(roman_to_int('MCCCCCCVI'))

f = open("p089_roman.txt")
line = f.readline()
while line:
    print(line[0:-1], end = ' ')
    xx = roman_to_int(line[0:-1])
    print(xx)
    ans += xx
    line = f.readline()
f.close()

print(ans)
