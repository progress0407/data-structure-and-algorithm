# 상대적으로 덜 중요

n = 10
arr = [[0] * n for _ in range(n)]
vis = [0] * n

arr[1][2] = 1
arr[2][1] = 1

arr[1][3] = 1
arr[3][1] = 1

arr[3][4] = 1
arr[4][3] = 1

def go(fr):
    vis[fr] = 1
    print(fr)
    for to in range(10):
        if arr[fr][to] == 1 and vis[to] == 0:
            go(to)


for i in range(n):
    for j in range(n):
        if arr[i][j] == 1 and vis[i] == 0:
            go(i)
