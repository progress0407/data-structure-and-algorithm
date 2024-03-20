n, m = map(int, input().split())
b = [int(input()) for _ in range(n)]


def go(idx, tree, cnt):
    if cnt < 0:
        return float('-inf')
    if idx == n:
        return 0 if cnt == 0 else float('-inf')

    ret = max(go(idx + 1, 1 if tree == 0 else 0, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1)
    return ret


print(max(go(0, 1, m - 1), go(0, 0, m)))
