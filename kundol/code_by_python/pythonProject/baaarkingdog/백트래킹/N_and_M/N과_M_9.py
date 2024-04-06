def backtrack(depth):
    if depth == M:
        res = tuple(arr[:M])
        res_set.add(res)
        return

    for i in range(N):
        if not is_used[i]:
            arr[depth] = origin_arr[i]
            is_used[i] = True
            backtrack(depth + 1)
            is_used[i] = False


if __name__ == '__main__':
    N, M = map(int, input().split())
    origin_arr = sorted(list(map(int, input().split())))
    arr = [-1 for _ in range(N)]
    is_used = [False for _ in range(N)]
    res_set = set()
    backtrack(0)
    res_set = sorted(res_set)
    for row in res_set:
        conv_row = map(str, row)
        print(' '.join(conv_row))
