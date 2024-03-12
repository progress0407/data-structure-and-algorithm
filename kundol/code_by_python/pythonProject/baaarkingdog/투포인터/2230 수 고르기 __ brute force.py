n, ideal_min = map(int, input().split())
# ideal_min 이상적인 최솟값

arr = [0] * (n)
for i in range(n):
    arr[i] = int(input())

arr.sort()
# 현재까지의 최솟값
cur_min = 2000000000 + 1

for i in range(0, n - 1):
    for j in range(i + 1, n):
        # 현재 값 차이
        curDiff = arr[j] - arr[i]
        if curDiff >= ideal_min and curDiff < cur_min:
            cur_min = curDiff
            if cur_min == ideal_min:
                break

print(cur_min)
