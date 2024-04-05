N, r, c = map(int, input().split())

N_2 = 1 << N

arr = [[0 for _ in range(N_2)] for _ in range(N_2)]


# 보정 계수
def recur_2d(side_size, y, x, cor):
    if side_size == 2:
        cnt = 0
        for dy in range(2):
            for dx in range(2):
                arr[y + dy][x + dx] = cor + cnt
                cnt += 1
        return

    next_side_size = side_size // 2
    rect_2d = next_side_size * next_side_size

    recur_2d(next_side_size, y, x, cor)
    recur_2d(next_side_size, y, x + next_side_size, cor + rect_2d)
    recur_2d(next_side_size, y + next_side_size, x, cor + rect_2d * 2)
    recur_2d(next_side_size, y + next_side_size, x + next_side_size, cor + rect_2d * 3)


recur_2d(N_2, 0, 0, 0)
# print(arr)
print(arr[r][c])
