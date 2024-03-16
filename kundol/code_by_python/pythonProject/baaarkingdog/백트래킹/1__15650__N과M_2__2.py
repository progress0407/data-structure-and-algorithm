N, M = map(int, input().split())

current_nums = [0 for _ in range(M + 1)]
is_used = [False for _ in range(N + 1)]


def do_backtracking(depth):
    if depth == M + 1:
        print(*current_nums[1:])
    else:
        start_index = 1
        for i in range(N, 0, -1):
            if is_used[i]:
                start_index = i
                break
        for i in range(start_index, N + 1):
            if not is_used[i]:
                current_nums[depth] = i
                is_used[i] = True
                do_backtracking(depth + 1)
                is_used[i] = False


do_backtracking(1)
