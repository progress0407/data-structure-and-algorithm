N, R, C = map(int, input().split())

N_2 = 1 << N

dot_arr = [[0, 1], [2, 3]]


def recur(n, c, r):
    if n == 2:
        return dot_arr[r][c]

    mid = n // 2
    area = mid * mid
    if 0 <= c < mid and 0 <= r < mid:  # 1사분면
        return recur(n // 2, c, r)

    elif mid <= c < 2 * mid and 0 <= r < mid:  # 2사분면
        return area + recur(mid, c - mid, r)

    elif 0 <= c < mid and mid <= r < 2 * mid:
        return 2 * area + recur(mid, c, r - mid)

    elif mid <= c < 2 * mid and mid <= r < 2 * mid:
        return 3 * area + recur(mid, c - mid, r - mid)


res = recur(N_2, C, R)
print(res)
