N, M = map(int, input().split())

arr = [-1 for _ in range(N)]


def backtrack(depth, idx):
    if depth == M:
        res = ' '.join(map(str, arr[:M]))
        print(res)
        return

    for i in range(N):
        if i >= idx:
            arr[depth] = i + 1
            backtrack(depth + 1, i)


if __name__ == '__main__':
    backtrack(0, -1)
