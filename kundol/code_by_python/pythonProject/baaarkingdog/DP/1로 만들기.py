n = int(input())
d = [0] * (n + 4)

d[0] = 0
d[1] = 0
d[2] = 1
d[3] = 1

if n <= 3:
    print(d[n])

for i in range(4, n + 1):
    candis = [d[i - 1] + 1]
    if i % 3 == 0:
        candis.append(d[i // 3] + 1)
    elif i % 2 == 0:
        candis.append(d[i // 2] + 1)
    d[i] = min(candis)

print(d[n])
