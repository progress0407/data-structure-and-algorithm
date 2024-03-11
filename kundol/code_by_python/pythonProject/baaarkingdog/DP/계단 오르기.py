rpt = int(input())

a = [0] * (rpt + 4)
d = [[0 for _ in range(3)] for _ in range(rpt + 4)]
dm = [0] * (rpt + 4)

for i in range(1, rpt + 1):
    a[i] = int(input())

d[1][1] = a[1]
d[1][2] = 0
d[2][1] = a[2]
d[2][2] = a[1] + a[2]

dm[1] = max(d[1][1], d[1][0])
dm[2] = max(d[2][1], d[2][0])

if rpt <= 2:
    print(dm[rpt])

for k in range(3, rpt + 1):
    d[k][1] = max(d[k - 2][1], d[k - 2][2]) + a[k]
    d[k][2] = d[k - 1][1] + a[k]
    dm[k] = max(d[k][1], d[k][2])

print(dm[rpt])
