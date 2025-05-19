# <p>For the year $2025$</p>
# $$2025 = (20 + 25)^2$$
# <p>Given positive integers $a$ and $b$, the concatenation $ab$ we call a $2025$-number if $ab = (a+b)^2$.<br>
# Other examples are $3025$ and $81$.<br>
# Note $9801$ is not a $2025$-number because the concatenation of $98$ and $1$ is $981$.</p>

# <p>
# Let $T(n)$ be the sum of all $2025$-numbers with $n$ digits or less. You are given $T(4) = 5131$.</p>

# <p>
# Find $T(16)$.</p>

import math

def is_2025_number(x):
  s = str(x)
  len_s = len(s)
  for i in range(1, len_s):
    a = int(s[:i])
    b = int(s[i:])
    if a == 0 or b == 0 or (s[i] == '0'):
      continue
    b_digit_number = math.floor(math.log10(b)) + 1
    if a * 10 ** b_digit_number + b == (a + b) ** 2:
      print(x, a, b)
      return True
  return False

def F(n):
  # How many n-digit numbers are 2025-numbers?
  # let's assume a have (n/2) digits, b have (n - n/2) digits
  print("processing n = ", n)
  a_digit_number = math.floor(n / 2)
  b_digit_number = n - a_digit_number
  a_min = max(int(10 ** (a_digit_number - 1)), 1)
  a_max = int(10 ** a_digit_number - 1)
  fix_b_min = int(10 ** (b_digit_number - 1))
  b_min = int(10 ** (b_digit_number - 1))
  b_max = int(10 ** b_digit_number - 1)
  # let's assume b_max is actually 3 * b_min
  b_max = 3 * b_min

  count = 0

  for a in range(a_min, a_max + 1):
    for b in range(b_min, b_max + 1):
      if a * 10 ** b_digit_number + b == (a + b) ** 2:
        print(a, b)
        count += int((a + b) ** 2)
      elif a * 10 ** b_digit_number + b < (a + b) ** 2:
        b_min = max(fix_b_min, b - 1)
        break
  return count

def T2(n):
  total = 0
  for i in range(1, n+1):
    total += F(i)
  return total

def T(n):
  total = 0
  for i in range(1, 10 ** n):
    if is_2025_number(i):
      total += i
  return total


# print(F(14))

# print(T(6))
# print(T2(6))

print(T2(16))


# 108257292415732771 is wrong
# 72673459417881349 is correct !
