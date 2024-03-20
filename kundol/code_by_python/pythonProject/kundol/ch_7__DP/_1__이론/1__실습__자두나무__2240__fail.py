T, W = map(int, input().split())

d = [[0 for _ in range(W)] for _ in range(T)]
# d[round][tree_no][move_cnt]
# round: 현재 라운드
# tree_no: 현재 tree의 넘버
# move_cnt: 지금까지 움직인 횟수
# d = 그때의 최대 자두 획득량

tree_input_list = []
for _ in range(T):
    tree_input_list.append(int(input()))

dp = [[[-1 for _ in range(W)] for _ in range(2)] for _ in range(T)]


def go(index, tree_no, move_cnt):
    if move_cnt > W:
        return -1 * (10 ** 8)
    if index == T:
        return 0

    gain_jadu = 1 if tree_no == tree_input_list[index] else 0

    next_tree_no = 2 if tree_no == 1 else 1
    return max(go(index + 1, tree_no, move_cnt), go(index + 1, next_tree_no, move_cnt + 1)) + gain_jadu


max_jadu_cnt = max(go(0, 1, 0), go(0, 2, 1))

print(max_jadu_cnt)
