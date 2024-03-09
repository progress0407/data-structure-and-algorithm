def sub_sum(arr, st, ed):
    arr_size = len(arr)
    sum_arr = [0] * (arr_size + 1)

    # s0=a0, s1=s0+a1, s2=s1+a2, s3=s2+a3
    for i in range(0, arr_size-1):
        sum_arr[i+1] = sum_arr[i] + arr[i+1]

    return sum_arr[ed] - sum_arr[st]

# 1 2 3 4 5
# 3~1
# 2+3+4
# 1~4 - 1~1 = s3 - s1
if __name__ == "__main__":
    arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    result = sub_sum(arr, 1, 4)
    print("result =", result)
