H, W = map(int, input().split())

cloud_2d = []
time_2d = [[-1 for _ in range(W)] for _ in range(H)]

for _ in range(H):
    cloud_2d.append(list(map(str, input())))

for y in range(H):
    cloud_ind_list = []
    for x in range(W):
        cloud_dot = cloud_2d[y][x]
        if cloud_dot == 'c':
            cloud_ind_list.append(x)
            time_2d[y][x] = 0
    for cloud_ind in cloud_ind_list:
        mx = cloud_ind + 1  # 구름이 이동한 위치
        tm = 1  # 구름의 이동시간
        while 0 <= mx < W and mx not in cloud_ind_list:
            time_2d[y][mx] = tm
            mx += 1
            tm += 1

for time_1d in time_2d:
    for t in time_1d:
        print(t, end=' ')
    print()