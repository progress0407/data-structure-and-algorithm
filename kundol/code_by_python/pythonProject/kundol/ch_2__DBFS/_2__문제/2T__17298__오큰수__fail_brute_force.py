N = int(input())
A = list(map(int, input().split()))

for i in range(N):
    is_exist = False
    for j in range(i, N):
        left = A[i]
        right = A[j]
        if left < right:
            A[i] = right
            is_exist = True
            break
    if not is_exist:
        A[i] = -1

A[N - 1] = -1

print(A)