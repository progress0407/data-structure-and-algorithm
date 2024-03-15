from sys import setrecursionlimit

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

# 세로, 가로, 좌표쌍의 갯수
m, n, k = map(int, input().split())
setrecursionlimit(m * n + 5)

a = [[1 for _ in range(n)] for _ in range(m)]
vis = [[0 for _ in range(n)] for _ in range(m)]


def dfs(y, x, s):
    vis[y][x] = 1
    s += 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < m and 0 <= nx < n and a[ny][nx] == 1 and vis[ny][nx] == 0:
            s += dfs(ny, nx, 0)
    return s


cnt = 0
for _ in range(k):
    lx, ly, hx, hy = map(int, input().split())

    for y in range(ly, hy):
        for x in range(lx, hx):
            a[y][x] = 0

sec_list = []
for y in range(m):
    for x in range(n):
        if a[y][x] == 1 and vis[y][x] == 0:
            sec = dfs(y, x, 0)
            sec_list.append(sec)
            cnt += 1

sec_list.sort()
print(cnt)
print(' '.join(map(str, sec_list)))
