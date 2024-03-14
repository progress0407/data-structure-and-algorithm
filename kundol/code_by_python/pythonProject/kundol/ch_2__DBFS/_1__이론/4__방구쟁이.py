dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

n, m = map(int, input().split())

mapp = [[0 for _ in range(m)] for _ in range(n)]
vis = [[0 for _ in range(m)] for _ in range(n)]
cnt = 0

def dfs(y, x):
    vis[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < n and 0 <= nx < m and mapp[ny][nx] == 1 and vis[ny][nx] == 0:
            dfs(ny, nx)

i = 0
for _ in range(n):
    j = 0
    for v in list(map(int, input().split())):
        mapp[i][j] = v
        j += 1
    i += 1

for i in range(n):
    for j in range(m):
        if mapp[i][j] == 1 and vis[i][j] == 0:
            dfs(i, j)
            cnt += 1

print(cnt)

# 5 5
# 1 0 1 0 1
# 1 1 0 0 1
# 0 0 0 1 1
# 0 0 0 1 1
# 0 1 0 0 0

