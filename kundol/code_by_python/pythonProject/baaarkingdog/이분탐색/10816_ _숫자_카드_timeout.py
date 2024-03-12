# 이분탐색으로 풀었지만 시간 초과

n = int(input())

i = 0
source_origin = [0] * n
for v in list(map(int, input().split())):
    source_origin[i] = v
    i += 1
source_origin.sort()

m = int(input())

i = 0
targets = [0] * m
for v in list(map(int, input().split())):
    targets[i] = v
    i += 1

cnt_arr = [0] * m


i = 0
for target in targets:

    source = source_origin.copy()
    st = 0
    ed = n - 1

    while st <= ed:
        mid = (st + ed) // 2
        if source[mid] == target:
            del source[mid]
            cnt_arr[i] += 1
            mid -= 1
            ed -= 1
        elif target < source[mid]:
            ed = mid - 1
        else:
            st = mid + 1
    i += 1

print(cnt_arr)
