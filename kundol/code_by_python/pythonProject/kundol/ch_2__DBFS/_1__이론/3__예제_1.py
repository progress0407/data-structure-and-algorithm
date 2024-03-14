dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

for i in range(4):
    y = 0
    x = 0
    for j in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        print(f'{ny} : {nx}')
