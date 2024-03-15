# 시간초과

T = int(input())

for _ in range(T):
    tot_10_cnt = 0
    target_whole_num = int(input())
    if target_whole_num < 5:
        print(0)
        continue

    target_max_num_5 = target_whole_num
    while target_max_num_5 % 5 != 0:
        target_max_num_5 -= 1
    for num in range(target_max_num_5, 4, -5):
        _10_cnt = 0
        while num >= 5 and num % 5 == 0:
            num //= 5
            _10_cnt += 1
        tot_10_cnt += _10_cnt
    print(tot_10_cnt)
