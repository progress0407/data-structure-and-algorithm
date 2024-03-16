dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

n, m = map(int, input().split())
mapp = [list(map(int, input().split())) for _ in range(n)]
vis = [[0 for _ in range(m)] for _ in range(n)]
one_loop_area = 0


def dfs(y, x):
    vis[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < n and 0 <= nx < m and mapp[ny][nx] == 1 and vis[ny][nx] == 0:
            dfs(ny, nx)


for y in range(n):
    for x in range(m):
        if mapp[y][x] == 1 and vis[y][x] == 0:
            dfs(y, x)
            one_loop_area += 1

print(one_loop_area)

# 5 5
# 1 0 1 0 1
# 1 1 0 0 1
# 0 0 0 1 1
# 0 0 0 1 1
# 0 1 0 0 0
