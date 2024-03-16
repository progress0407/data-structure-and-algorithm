from itertools import permutations

N, M = map(int, input().split())

current_nums = [0 for _ in range(M)]
is_used = [False for _ in range(N + 1)]


def backtrack(depth):
    if depth == M:
        print(' '.join(map(str, current_nums)))
    else:
        for num in range(1, N + 1):
            if not is_used[num]:
                current_nums[depth] = num
                is_used[num] = True
                backtrack(depth + 1)
                is_used[num] = False


backtrack(0)
