import sys

n, ideal_min = map(int, input().split())
# ideal_min 이상적인 최솟값

arr = [0] * (n)
for i in range(n):
    arr[i] = int(input())

arr.sort()

# 현재까지의 조건을 만족하는 최솟값
min_candi = 2000000000 + 1

st = 0
ed = 1

if n == 1 and ideal_min == 0:
    print(0)
    sys.exit(0)

while True:
    cur_diff = arr[ed] - arr[st]
    if cur_diff >= ideal_min:
        min_candi = cur_diff
        if cur_diff == ideal_min:
            print(cur_diff)
            sys.exit(0)
        else:
            st += 1
    else:
        ed += 1

    if (ed > n - 1 or st > n - 1 or st > ed):
        break

print(min_candi)
