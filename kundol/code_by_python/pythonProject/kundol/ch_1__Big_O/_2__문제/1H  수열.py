# import numpy as np

n, k = map(int, input().split())

li = list(map(int, input().split()))
# li = np.array(list(map(int, input().split())))

arr = [0] * (n+4)
i = 0
for v in li:
    arr[i] = v
    i+=1

sum_li = []
for i in range(n-k):
    sum_val = 0
    for j in range(i, i+k):
        sum_val += arr[j]
    sum_li.append(sum_val)

print(max(sum_li))
