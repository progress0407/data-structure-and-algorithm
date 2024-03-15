import copy
import sys

sys.setrecursionlimit(10000)

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

tc = int(input())


def dfs(y, x):
    vis[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < n and 0 <= nx < m and mapp[ny][nx] == 1 and vis[ny][nx] == 0:
            vis[ny][nx] = 1
            dfs(ny, nx)


for _ in range(tc):
    # 가로, 세로, 배추 위치 갯수
    m, n, k = map(int, input().split())
    cnt = 0

    mapp = [[0 for _ in range(m)] for _ in range(n)]
    vis = copy.deepcopy(mapp)

    for _ in range(k):
        x, y = map(int, input().split())
        mapp[y][x] = 1

    for y in range(n):
        for x in range(m):
            if 0 <= y < n and 0 <= x < m and mapp[y][x] == 1 and vis[y][x] == 0:
                vis[y][x] = 1
                dfs(y, x)
                cnt += 1

    print(cnt)
