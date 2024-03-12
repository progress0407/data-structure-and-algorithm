n, s = map(int, input().split())

arr = [0] * n
i = 0
for v in list(map(int, input().split())):
    arr[i] = v
    i += 1

arr.sort()

st = 0
ed = 0
min_len = n
while True:
    mid_sum = 0
    for i in range(st, ed + 1):
        mid_sum += arr[i]
    if mid_sum >= s:
        cur_diff = ed - st + 1
        min_len = min(min_len, cur_diff)
        st += 1
    else:
        ed += 1
    if ed > n - 1 or st > n-1 or st > ed:
        break

print(min_len)
