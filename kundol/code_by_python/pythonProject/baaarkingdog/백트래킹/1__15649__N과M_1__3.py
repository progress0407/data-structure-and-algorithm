N, M = map(int, input().split())

# index: 1 ~ M
# 뽑힌 갯수
current_nums = [-1 for _ in range(M + 1)]
# index: 1 ~ N
is_used = [False for _ in range(N + 1)]


def do_backtracking(depth):
    if depth == M + 1:
        res = ' '.join(map(str, current_nums[1:]))
        print(res)
    else:
        for num in range(1, N + 1):
            if not is_used[num]:
                current_nums[depth] = num
                is_used[num] = True
                do_backtracking(depth + 1)
                is_used[num] = False


do_backtracking(1)
