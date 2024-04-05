N = 10


def sub_sum_asc(cur_idx, cur_sum):
    if cur_idx == 10:
        return cur_sum
    return sub_sum_asc(cur_idx + 1, cur_sum + cur_idx + 1)


def sub_sum_desc(cur_idx, cur_sum):
    if cur_idx == 0:
        return cur_sum
    return sub_sum_desc(cur_idx - 1, cur_sum + cur_idx)


# 바킹독 센세
def sub_sum_barrk(n):
    if n == 0:
        return 0
    return n + sub_sum_barrk(n - 1)


if __name__ == '__main__':
    # tot_sum = sub_sum_asc(N, 0)
    # tot_sum = sub_sum_desc(N, 0)
    tot_sum = sub_sum_barrk(N)
    print(tot_sum)
