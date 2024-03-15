# 시간초과

T = int(input())

for _ in range(T):
    tot_10_cnt = 0
    target_whole_num = int(input())
    if target_whole_num < 5:
        print(0)
        continue

    _5_num = 5  # 5의 거듭 제곱
    while _5_num <= target_whole_num:
        tot_10_cnt += target_whole_num // _5_num
        _5_num *= 5
    print(tot_10_cnt)