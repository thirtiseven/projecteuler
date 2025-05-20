def max_power_of_2_under(n):
  x = n
  i = 0
  while x > 0:
    x = x // 2
    i += 1
  return 2 ** (i - 1)


def gao(n, k):
  diff = n - k

  path = []
  while diff > 0:
    max_power = max_power_of_2_under(diff)
    diff = diff - max_power
    path.append(max_power)

  # reverse the path
  path.reverse()

  cur = n
  sum = n
  for item in path:
    cur -= item
    sum += cur

  print(cur)

  print(sum)

  print("=====")

gao(6, 1)

gao(10, 3)

gao(int(10**17), int(9**17))