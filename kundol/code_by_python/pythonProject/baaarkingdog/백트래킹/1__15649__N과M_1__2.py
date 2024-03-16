N, M = map(int, input().split())

current_nums = [0 for _ in range(M + 1)]
is_used = [False for _ in range(N + 1)]


def do_backtracking(depth):
    if depth == M + 1:
        print(*current_nums[1:])
    else:
        for i in range(1, N + 1):
            if not is_used[i]:
                current_nums[depth] = i
                is_used[i] = True
                do_backtracking(depth + 1)
                is_used[i] = False


do_backtracking(1)
