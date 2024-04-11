from copy import deepcopy


def bactrack(y, x):
    global cnt

    for ny in range(y + 1, N):
        for nx in range(N):
            if mark_mapp[ny][nx] == 0 and (x == nx or x + y == nx + ny or x - y == nx - ny):
                # 여기있는 2 또한 원복 대상임
                mark_mapp[ny][nx] = 2

    ny = y + 1
    for nx in range(N):
        print(f'ny, nx = ({ny}, {nx})')
        if mark_mapp[ny][nx] not in (1, 2):
            if ny < N - 1:
                mark_mapp[ny][nx] = 1
                bactrack(ny, nx)
                mark_mapp[ny][nx] = 0
            else:
                cnt += 1
                return


if __name__ == '__main__':
    N = int(input())
    mapp = [[0 for _ in range(N)] for _ in range(N)]
    # 0: 빈공간
    # 1: 퀸 위치 곳
    # 2: 마킹된 곳, 퀸을 못 놓는 곳
    mark_mapp = [[0 for _ in range(N)] for _ in range(N)]
    cnt = 0
    # print(mapp)
    y = 0
    for x in range(N):
        mark_mapp[y][x] = 1
        bactrack(y, x)
        mark_mapp[y][x] = 0
        mark_mapp = deepcopy(mapp)
    print(cnt)
