from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

# 맵
n, m = map(int, input().split())

# 승원이 위치
x1, y1 = map(int, input().split())

# 당근마킷 위치
x2, y2 = map(int, input().split())

mapp = [list(map(int, input().split())) for _ in range(n)]
vis = [[0 for _ in range(m)] for _ in range(n)]

que = deque()
que.append((x1, y1))
vis[y1][x1] = 1

while len(que) > 0:
    y, x = que.popleft()
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < n and 0 <= nx < m and mapp[ny][nx] == 1 and vis[ny][nx] == 0:
            que.append((ny, nx))
            vis[ny][nx] = vis[y][x] + 1

print(vis[y2][x2])