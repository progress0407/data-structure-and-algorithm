N, M = map(int, input().split())

is_used = [False for _ in range(N)]
arr = [-1 for i in range(N)]


def backtrack(depth, idx):
    if depth == M:
        res = ' '.join(map(str, arr[:M]))
        print(res)
        return

    for i in range(N):
        if i > idx and not is_used[i]:
            arr[depth] = i + 1
            is_used[i] = True
            backtrack(depth + 1, i)
            is_used[i] = False


if __name__ == '__main__':
    backtrack(0, -1)
