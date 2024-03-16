from itertools import combinations
from copy import deepcopy
from sys import setrecursionlimit

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

n, m = map(int, input().split())
setrecursionlimit(n * m + 4)

origin_map = [list(map(int, input().split())) for _ in range(n)]
mapp = [[]]

empty_coord_list = []
virus_coord_list = []
one_loop_area = 0
max_area = 0

for y in range(n):
    for x in range(m):
        cur_obj = origin_map[y][x]
        dot = (y, x)
        if cur_obj == 0:
            empty_coord_list.append(dot)
        elif cur_obj == 2:
            virus_coord_list.append(dot)

wall_coords_list = list(combinations(empty_coord_list, 3))


def dfs(y, x):
    mapp[y][x] = 2
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < n and 0 <= nx < m and mapp[ny][nx] == 0:
            dfs(ny, nx)


for wall_coords in wall_coords_list:

    # 시나리오 시작
    mapp = deepcopy(origin_map)

    # 벽 세우기
    for y, x in wall_coords:
        mapp[y][x] = 1

    # 바이러스 퍼뜨리기
    for y, x in virus_coord_list:
        dfs(y, x)

    # 안전영역의 크기
    one_loop_area = 0
    for row in mapp:
        for e in row:
            if e == 0:
                one_loop_area += 1

    max_area = max(max_area, one_loop_area)

print(max_area)