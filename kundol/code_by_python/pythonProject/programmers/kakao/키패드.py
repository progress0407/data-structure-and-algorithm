def solution(_numbers, hand):
    numbers = list(map(str, _numbers))

    keypad = [
        ['1', '2', '3'],
        ['4', '5', '6'],
        ['7', '8', '9'],
        ['*', '0', '#']
    ]
    H = len(keypad)
    W = len(keypad[0])

    left_side = [(0, 0), (1, 0), (2, 0), (3, 0)]
    right_side = [(0, 2), (1, 2), (2, 2), (3, 2)]

    left_pos = (3, 0)
    right_pos = (3, 2)

    answer = ''

    for number in numbers:
        num_pos = ()
        for y in range(H):
            for x in range(W):
                if number == keypad[y][x]:
                    num_pos = (y, x)
                    break
        if num_pos in left_side:
            left_pos = num_pos
            answer += 'L'
        elif num_pos in right_side:
            right_pos = num_pos
            answer += 'R'
        else:
            left_dist = abs(left_pos[0] - num_pos[0]) + abs(left_pos[1] - num_pos[1])
            right_dist = abs(right_pos[0] - num_pos[0]) + abs(right_pos[1] - num_pos[1])
            if left_dist < right_dist:
                left_pos = num_pos
                answer += 'L'
            elif left_dist > right_dist:
                right_pos = num_pos
                answer += 'R'
            else:
                if hand == 'left':
                    left_pos = num_pos
                    answer += 'L'
                else:
                    right_pos = num_pos
                    answer += 'R'

    return answer


# moves = [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]
# hand = "right"
# print("LRLLLRLLRRL" == solution(moves, hand))

moves = [7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2]
hand = "left"
res = solution(moves, hand)
print("LRLLRRLLLRR" == res)

# moves = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
# hand = "right"
# print("LLRLLRLLRL" == solution(moves, hand))
