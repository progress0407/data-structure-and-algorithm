a, b, c = map(int, input().split())

res = 1
for _ in range(b):
    res = (res * a) % c

res %= c

print(res)
