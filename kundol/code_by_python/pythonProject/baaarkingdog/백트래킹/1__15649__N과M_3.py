N, M = map(int, input().split())

# index: 1 ~ M
# 뽑힌 갯수
current_nums = [-1 for _ in range(M + 1)]


def do_backtracking(depth):
    if depth == M + 1:
        print(' '.join(map(str, current_nums[1:])))
        return
    else:
        for num in range(1, N + 1):
            current_nums[depth] = num
            do_backtracking(depth + 1)


do_backtracking(1)
