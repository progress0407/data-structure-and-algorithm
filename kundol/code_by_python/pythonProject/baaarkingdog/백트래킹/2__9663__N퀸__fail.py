from copy import deepcopy

dy = [-1, 0, 1, 0, -1, -1, 1, 1]
dx = [0, 1, 0, -1, 1, -1, 1, -1]

N = int(input())

pure_mapp = [[0 for _ in range(N)] for _ in range(N)]

# 0 빈공간
# 1 퀸 착수 지점
# 2 퀸을 놓을 수 없는 곳

for y in range(N):
    for x in range(N):
        mapp = deepcopy(pure_mapp)
        if mapp[y][x] == 0:
            mapp[y][x] = 1

        ny = y
        nx = x
        for i in range(8):
            while 0 <= nx < N and 0 <= ny < N:
                ny += dy[i]
                nx += dx[i]
                if mapp[ny][nx] == 0:
                    mapp[ny][nx] = 2
