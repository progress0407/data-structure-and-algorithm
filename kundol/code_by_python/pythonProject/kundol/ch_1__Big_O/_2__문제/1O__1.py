while True:
    div_num = int(input())
    only_one_num = 1
    cnt = 1
    while True:
        if only_one_num % div_num == 0:
            break
        else:
            # only_one_num = int(str(only_one_num) + '1') % div_num
            only_one_num = (only_one_num * 10 + 1) % div_num
            cnt += 1
    print(cnt)
