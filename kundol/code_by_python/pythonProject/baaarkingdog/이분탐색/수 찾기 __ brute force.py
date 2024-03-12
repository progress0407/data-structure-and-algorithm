n = int(input())

arr = [0] * n
i = 0
for v in list(map(int, input().split())):
    arr[i] = v
    i += 1

m = int(input())

searches = [0] * n
i = 0
for v in list(map(int, input().split())):
    searches[i] = v
    i += 1


def has_same_number():
    for val in arr:
        if val == search:
            return 1
    return 0


for search in searches:
    ans = has_same_number()
    print(ans)
