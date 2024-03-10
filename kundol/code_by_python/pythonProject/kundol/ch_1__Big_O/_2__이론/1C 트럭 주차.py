a, b, c = map(int, input().split())
a = a
b = b * 2
c = c * 3

li = []
for i in range(3):
    st, ed = map(int, input().split())
    li.append((st, ed))

st = min([e[0] for e in li])
ed = max([e[1] for e in li])

arr = [0] * (ed + 4)

for st, ed in li:
    for i in range(st, ed):
        arr[i] += 1

s = 0
for v in arr:
    if v == 1:
        s += a
    elif v == 2:
        s += b
    elif v == 3:
        s += c

print(s)
