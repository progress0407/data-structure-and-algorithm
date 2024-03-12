from functools import reduce

n, m = map(int, input().split())
val_li = list(map(int, input().split()))

pair_li = []
for i in range(m):
    pair_li.append(tuple(map(int, input().split())))

for pair in pair_li:
    st = pair[0]
    ed = pair[1]

    sum = reduce(lambda x, y: x + y, val_li[st - 1:ed])
    print(sum)
