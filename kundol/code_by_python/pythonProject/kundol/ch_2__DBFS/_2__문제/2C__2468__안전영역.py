from copy import deepcopy
from sys import setrecursionlimit

# 안전지역은 1이고 물에 잠긴 부분은 0이다

# 알고리즘:
# 처음에 모두 1으로 표시
# 물에 잠긴 부분 0으로 표시
# 1에 대한 connected component 계산

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

n = int(input())
setrecursionlimit(n * n * n)

mapp = [list(map(int, input().split())) for _ in range(n)]
max_h = 0
for y in range(n):
    for x in range(n):
        max_h = max(mapp[y][x], max_h)

_map = []
vis = []
max_cnt = 0


def dfs(y, x):
    vis[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < n and 0 <= nx < n:
            if _map[ny][nx] == 1 and vis[ny][nx] == 0:
                dfs(ny, nx)


# h 비의 높이
for h in range(0, max_h + 1):
    _map = [[1 for _ in range(n)] for _ in range(n)]
    vis = [[0 for _ in range(n)] for _ in range(n)]
    for y in range(n):
        for x in range(n):
            if mapp[y][x] <= h:
                _map[y][x] = 0

    one_loop_area = 0
    for y in range(n):
        for x in range(n):
            if _map[y][x] == 1 and vis[y][x] == 0:
                dfs(y, x)
                one_loop_area += 1
    max_cnt = max(one_loop_area, max_cnt)
    # print(f'h={h}, cnt = {cnt}')
# print(f'max_cnt = {max_cnt}')
print(max_cnt)
