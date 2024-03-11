rpt = int(input())

arr = [0] * (rpt)
for i in range(rpt):
    r, g, b = map(int, input().split())
    arr[i] = (r, g, b)

d = [[0 for _ in range(3)] for _ in range(rpt)]
dtot = [0] * rpt

d[0][0] = arr[0][0]
d[0][1] = arr[0][1]
d[0][2] = arr[0][2]

dtot[0] = min(d[0][0], d[0][1], d[0][2])

if rpt == 1:
    print(dtot[1])

for i in range(1, rpt):
    d[i][0] = arr[i][0] + min(d[i - 1][1], (d[i - 1][2]))
    d[i][1] = arr[i][1] + min(d[i - 1][0], (d[i - 1][2]))
    d[i][2] = arr[i][2] + min(d[i - 1][0], (d[i - 1][1]))

dtot[rpt - 1] = min(d[rpt - 1][0], d[rpt - 1][1], d[rpt - 1][2])

print(dtot[rpt - 1])
