N, M = map(int, input().split())

arr = [-1 for i in range(N)]
is_used = [False for i in range(N)]


def backtrack(depth):
    if depth == M:
        semi_res = ''
        for i in range(M):
            semi_res += str(arr[i]) + ' '
        print(semi_res.strip())
        return

    for i in range(N):
        if not is_used[i]:
            arr[depth] = i + 1
            is_used[i] = True
            backtrack(depth + 1)
            is_used[i] = False


if __name__ == '__main__':
    backtrack(0)
