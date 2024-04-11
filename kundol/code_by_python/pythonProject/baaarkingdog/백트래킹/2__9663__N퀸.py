def bactrack(y):
    global cnt

    if y == N:
        cnt += 1
        return

    for x in range(N):
        if is_used_1[x] or is_used_2[x + y] or is_used_3[x - y + N - 1]:
            continue

        is_used_1[x] = True
        is_used_2[x + y] = True
        is_used_3[x - y + N - 1] = True

        bactrack(y + 1)

        is_used_1[x] = False
        is_used_2[x + y] = False
        is_used_3[x - y + N - 1] = False


if __name__ == '__main__':
    N = int(input())

    is_used_1 = [False for _ in range(N)]
    is_used_2 = [False for _ in range(2 * N - 1)]
    is_used_3 = [False for _ in range(2 * N - 1)]
    cnt = 0

    bactrack(0)

    print(cnt)
