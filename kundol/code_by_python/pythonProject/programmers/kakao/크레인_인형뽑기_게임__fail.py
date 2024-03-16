def solution(board, moves):
    answer = 0
    stk = []
    height = len(board)  # 보드의 높이

    for pos in moves:
        pos -=1  # 크레인 위치

        for h in range(0, height):

            doll = board[h][pos]

            if doll == 0:  # 인형 없는 경우
                continue
            else:  # 인형이 있는 경우
                board[pos][h] = 0
                if len(stk) == 0:
                    stk.append(doll)
                else:
                    top = stk[-1]

                    if top == doll:
                        stk.pop()
                        answer += 2
                    else:
                        stk.append(doll)

    return answer


board = \
    [
        [0, 0, 0, 0, 0],
        [0, 0, 1, 0, 3],
        [0, 2, 5, 0, 1],
        [4, 2, 4, 4, 2],
        [3, 5, 1, 3, 1]
    ]


ans = solution(board,
               [1, 5, 3, 5, 1, 2, 1, 4])

print(ans)
