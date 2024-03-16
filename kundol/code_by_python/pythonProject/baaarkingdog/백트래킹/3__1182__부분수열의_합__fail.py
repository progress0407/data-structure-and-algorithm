N, S = map(int, input().split())

# index: 1 ~ M
# 뽑힌 갯수
current_nums = [-1 for _ in range(N + 1)] # -1 마킹용 숫자
# index: 1 ~ N
is_used = [False for _ in range(N + 1)]

input_nums = [-1] + list(map(int, input().split()))

print(input_nums)

cnt = 0


def do_backtracking(target_index):
    effective_current_nums = list(filter(lambda n: n != -1, current_nums))
    # print(*effective_current_nums)

    global cnt
    sum_ = sum(effective_current_nums)  # -1이 아닌 것들의 합 == 실제 유효한 값들의 합
    if sum_ == S and len(effective_current_nums) > 0:
        # print('this ! total sum eq S! :  ', end='')
        # print(*effective_current_nums)
        cnt += 1

    for i in range(target_index + 1, N + 1):
        current_nums[i] = input_nums[i]
        do_backtracking(i)
        current_nums[i] = -1


do_backtracking(0)

print(cnt)
