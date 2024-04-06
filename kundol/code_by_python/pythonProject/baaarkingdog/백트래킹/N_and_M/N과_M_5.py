def backtrack(depth, idx):
    if depth == M:
        res = ' '.join(map(str, arr[:M]))
        print(res)
        return

    for i in range(N):
        if not is_used[i]:
            arr[depth] = origin_arr[i]
            is_used[i] = True
            backtrack(depth + 1, i)
            is_used[i] = False


if __name__ == '__main__':
    N, M = map(int, input().split())
    origin_arr = sorted(list(map(int, input().split())))
    arr = [-1 for _ in range(N)]
    is_used = [False for _ in range(N)]
    backtrack(0, -1)
