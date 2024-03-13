a, b, c = map(int, input().split())

res = 1

for _ in range(b):
    res *= a
    res %= c

print(res % c)
