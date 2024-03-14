dy = [-1, 0, 1, 0]
dx = [0, 1, 0, 1]

n = 3
mapp = [
    [1, 0, 1],
    [1, 0, 1],
    [0, 1, 1]
]

vis = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    for j in range(n):
        # 길이 있고 아직 방문하지 않은 곳을 방문한다
        if mapp[i][j] == 1 and vis[i][j] == 0:
            vis[i][j] = 1
            print(f'({i}, {j})')
