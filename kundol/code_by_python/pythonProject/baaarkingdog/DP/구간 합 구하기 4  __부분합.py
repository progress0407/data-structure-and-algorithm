from functools import reduce

n, m = map(int, input().split())
val_li = list(map(int, input().split()))
sum_li = [0] * m
sum_li[0] = val_li[0]
for i in range(1, m):
    sum_li[i] += sum_li[i - 1]

pair_li = []
for i in range(m):
    pair_li.append(tuple(map(int, input().split())))

for pair in pair_li:
    st = pair[0]
    ed = pair[1]

    sub_sum = sum_li[ed] - sum_li[st - 1]
    print(sub_sum)
