n = int(input())

arr = [0] * n
i = 0
for v in list(map(int, input().split())):
    arr[i] = v
    i += 1

arr.sort()

m = int(input())

searches = [0] * m
i = 0
for v in list(map(int, input().split())):
    searches[i] = v
    i += 1


def does_found():
    global ed, st
    while st <= ed:
        mid = (st + ed) // 2
        if arr[mid] == target:
            return True
        elif arr[mid] > target:
            ed = mid - 1
        else:
            st = mid + 1
    return False


for target in searches:
    st = 0
    ed = n - 1
    print(1) if does_found() else print(0)

