import sys

n = int(input())

d = [0] * (n + 4)
d[1] = 1
d[2] = 2

if n <= 2:
    print(d[n])
    sys.exit(0)
    # return 0

for i in range(3, n + 1):
    d[i] = d[i - 1] + d[i - 2]
    d[i] %= 10007

print(d[n])
