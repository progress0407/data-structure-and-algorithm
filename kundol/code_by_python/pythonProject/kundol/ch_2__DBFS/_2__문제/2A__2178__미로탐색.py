from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

n, m = map(int, input().split())
mapp = [list(map(int, input())) for _ in range(n)]
vis = [[0 for _ in range(m)] for _ in range(n)]

sy = 0
sx = 0

ey = n - 1
ex = m - 1

que = deque()
que.append((sy, sx))
vis[sy][sx] = 1

while len(que):
    y, x = que.popleft()

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < n and 0 <= nx < m and mapp[ny][nx] == 1 and vis[ny][nx] == 0:
            que.append((ny, nx))
            vis[ny][nx] = vis[y][x] + 1

print(vis[ey][ex])
