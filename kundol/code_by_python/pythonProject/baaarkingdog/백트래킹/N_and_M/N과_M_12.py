def backtrack(depth, idx):
    if depth == M:
        row = tuple(arr[:M])
        res_set.add(row)
        return

    for i in range(N):
        if i >= idx:
            arr[depth] = origin_arr[i]
            backtrack(depth + 1, i)


if __name__ == '__main__':
    N, M = map(int, input().split())
    origin_arr = sorted(list(map(int, input().split())))
    arr = [-1 for _ in range(N)]
    res_set = set()
    backtrack(0, -1)
    res_set = sorted(res_set)
    for row in res_set:
        res = ' '.join(map(str, row))
        print(res)
