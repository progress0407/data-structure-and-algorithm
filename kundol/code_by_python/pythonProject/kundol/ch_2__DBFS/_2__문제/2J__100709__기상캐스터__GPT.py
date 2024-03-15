H, W = map(int, input().split())
sky = [input() for _ in range(H)]
clouds = [[-1 for _ in range(W)] for _ in range(H)]

for i in range(H):
    cloud_time = -1  # 구름이 다음 구역에 도달하기까지 걸리는 시간
    for j in range(W):
        if sky[i][j] == 'c':  # 구름이 있는 구역 발견
            cloud_time = 0
        elif cloud_time >= 0:  # 구름이 이전 구역에서부터 이동 중
            cloud_time += 1
        clouds[i][j] = cloud_time

for row in clouds:
    print(' '.join(map(str, row)))