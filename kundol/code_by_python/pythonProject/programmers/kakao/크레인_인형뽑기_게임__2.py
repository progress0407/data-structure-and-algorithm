def solution(board, moves):
    H = len(board)
    W = len(board[0])
    stk = []
    answer = 0

    for _x in moves:
        x = _x - 1
        poll = 0
        for y in range(H):
            if board[y][x] == 0:
                continue
            else:
                poll = board[y][x]
                board[y][x] = 0
                break

        if poll == 0:
            continue

        if len(stk) == 0:
            stk.append(poll)
        else:
            last = stk[-1]
            if last == poll:
                stk.pop()
                answer += 2
            else:
                stk.append(poll)

    return answer


board = \
    [
        [0, 0, 0, 0, 0],
        [0, 0, 1, 0, 3],
        [0, 2, 5, 0, 1],
        [4, 2, 4, 4, 2],
        [3, 5, 1, 3, 1]
    ]
moves = [1, 5, 3, 5, 1, 2, 1, 4]
res = solution(board, moves)

print(res)
