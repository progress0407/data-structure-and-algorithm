n = int(input())

d = [[0, []] for _ in range(n + 4)]
d[1][0] = 0  # 가중치
d[1][1] = [1]  # 경로 히스토리

for k in range(2, n + 1):

    minWeight = d[k - 1][0]
    routeHistory = d[k - 1][1]

    if k % 3 == 0:
        if minWeight > d[k // 3][0]:
            minWeight = d[k // 3][0]
            routeHistory = d[k // 3][1]
    elif k % 2 == 0:
        if minWeight > d[k // 2][0]:
            minWeight = d[k // 2][0]
            routeHistory = d[k // 2][1]

    d[k][0] = minWeight + 1
    d[k][1].extend(routeHistory)  # flat으로 추가하기
    d[k][1].append(k)

print(d[n][0])
print(*reversed(d[n][1]))
