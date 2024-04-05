import sys

total_round, move_cnt_max = map(int, input().split())

dp = [[-1 for _ in range(x + 2)] for x in range(total_round)]
jadu_list = [int(input()) for _ in range(total_round)]


def count_if_pos_same(round_index, move_cnt):
    current_post = 1 if move_cnt % 2 == 0 else 2
    jadu_tree_no = jadu_list[round_index]

    return 1 if jadu_tree_no == current_post else 0


dp[0][0] = count_if_pos_same(0, 0)
dp[0][1] = count_if_pos_same(0, 1)

if total_round == 1:
    print(max(dp[0][0], dp[0][1]))
    sys.exit(0)

for round_index in range(1, total_round):

    move_cnt = 0
    dp[round_index][move_cnt] = dp[round_index - 1][move_cnt] + count_if_pos_same(round_index, move_cnt)

    round_min_pivot = min(round_index, move_cnt_max)
    for move_cnt in range(1, round_min_pivot + 1):
        # if move_cnt == -1:
        #     break
        dp[round_index][move_cnt] = max(dp[round_index - 1][move_cnt - 1], dp[round_index - 1][move_cnt]) + count_if_pos_same(round_index, move_cnt)

        # if move_cnt == -1:
        #     continue
        if move_cnt == round_min_pivot:
            if move_cnt == round_index:
                dp[round_index][move_cnt] = dp[round_index - 1][move_cnt - 1] + count_if_pos_same(round_index, move_cnt)
            else:
                dp[round_index][move_cnt] = max(dp[round_index - 1][move_cnt - 1], dp[round_index - 1][move_cnt]) + count_if_pos_same(round_index, move_cnt)

round_min_pivot = min(total_round-1, move_cnt_max)
res = max([dp[total_round - 1][i] for i in range(round_min_pivot + 1)])
print(res)
