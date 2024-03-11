rpt = int(input())


def dp(n):
    d = [0] * (n + 4)
    d[0] = -1 # 예외
    d[1] = 1
    d[2] = 2
    d[3] = 4

    if n <= 3:
        return d[n]

    for i in range(4, n + 1):
        # a_n = a_n-1 + a_n-2 + a_n-3
        d[i] = d[i - 1] + d[i - 2] + d[i - 3]
        # for j in range(i - 1, i - 4, -1):
        #     d[i] += d[j]

    return d[n]


for _ in range(rpt):
    n = int(input())
    ans = dp(n)
    print(ans)
