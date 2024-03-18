def solution(triangle):
    H = len(triangle)
    dp = [[-1 for i in range(len(j))] for j in triangle]

    dp[0][0] = triangle[0][0]
    if H == 1:
        return dp[0][0]

    for y in range(1, H):
        for x in range(y + 1):
            if x == 0:
                dp[y][x] = triangle[y][x] + dp[y - 1][x]
            elif x == y:
                dp[y][x] = triangle[y][x] + dp[y - 1][x - 1]
            else:
                dp[y][x] = triangle[y][x] + max(dp[y - 1][x - 1], dp[y - 1][x])

    max_num = max(dp[H - 1])

    return max_num


if __name__ == '__main__':
    print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]) == 30)
