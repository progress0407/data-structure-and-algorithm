rpt = int(input())

arr = [0] * (rpt + 4)
for i in range(rpt + 1):
    if i == 0: continue
    r, g, b = map(int, input().split())
    arr[i] = (0, r, g, b)

d = [[0 for _ in range(3 + 1)] for _ in range(rpt + 4)]
dtot = [0] * (rpt + 4)

d[1][1] = arr[1][1]
d[1][2] = arr[1][2]
d[1][3] = arr[1][3]

dtot[1] = min(d[1][1], d[1][2], d[1][3])

if rpt == 1:
    print(dtot[1])

for i in range(2, rpt + 1):
    d[i][1] = arr[i][1] + min(d[i - 1][2], (d[i - 1][3]))
    d[i][2] = arr[i][2] + min(d[i - 1][1], (d[i - 1][3]))
    d[i][3] = arr[i][3] + min(d[i - 1][1], (d[i - 1][2]))

dtot[rpt] = min(d[rpt][1], d[rpt][2], d[rpt][3])

print(dtot[rpt])
