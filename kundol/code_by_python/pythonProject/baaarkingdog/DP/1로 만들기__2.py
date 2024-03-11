n = int(input())
d = [0] * (n + 4)

d[0] = 0
d[1] = 0

if n <= 1:
    print(d[n])

for i in range(2, n + 1):
    d[i] = d[i - 1] + 1
    if i % 2 == 0:
        d[i] = min(d[i // 2] + 1, d[i])
    if i % 3 == 0:
        d[i] = min(d[i // 3] + 1, d[i])

print(d[n])
