# 생각해보면 누적합으로는 풀 수 없는 문제이다
def solve(a):
    size = len(a)
    s_arr = [0] * size

    s_arr[0] = a[0]
    for i in range(0, size - 1):
        s_arr[i + 1] = s_arr[i] + a[i + 1]

    st = -1
    ed = -1

    for i in range(size):
        for j in range(i):
            sum = s_arr[i] - s_arr[j]
            if sum == 100:
                print(f"sum = {sum}")
                ed = i
                st = j
    return st, ed


inp_num = [int(input()) for _ in range(9)]

a = sorted(inp_num)
st, ed = solve(a)

ans = [a[i] for i in range(st-1, ed+1)]

for i in ans:
    print(i)

