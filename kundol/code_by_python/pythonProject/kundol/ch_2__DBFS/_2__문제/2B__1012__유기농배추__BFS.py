from collections import deque
import copy

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

tc = int(input())

def bfs(y, x):
    que = deque()
    que.append((y, x))
    while len(que) > 0:
        y, x = que.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < n and 0 <= nx < m and mapp[y][x] == 1 and vis[ny][nx] == 0:
                que.append((ny, nx))
                vis[ny][nx] = 1


for _ in range(tc):
    m, n, k = map(int, input().split())
    mapp = [[0 for _ in range(m)] for _ in range(n)]
    vis = copy.deepcopy(mapp)
    cnt = 0

    for _ in range(k):
        x, y = map(int, input().split())
        mapp[y][x] = 1

    for y in range(n):
        for x in range(m):
            if mapp[y][x] == 1 and vis[y][x] == 0:
                bfs(y, x)
                cnt += 1

    print(cnt)
