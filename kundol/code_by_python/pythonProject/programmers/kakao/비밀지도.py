def solution(N, ARR1, ARR2):
    mapp1 = create_num_map(N, ARR1)
    mapp2 = create_num_map(N, ARR2)
    decoded_map = []

    for y in range(N):
        decoded_map_row = ''
        for x in range(N):
            dot1 = mapp1[y][x]
            dot2 = mapp2[y][x]

            if dot1 or dot2:
                decoded_map_row += '#'
            else:
                decoded_map_row += ' '
        decoded_map.append(decoded_map_row)

    return decoded_map


def create_num_map(N, arr):
    mapp = []
    for row in arr:
        bin_str = f'{bin(row)[2:].zfill(N)}'
        conv_row = [int(ch) for ch in bin_str]
        mapp.append(conv_row)
    return mapp


def case_1():
    res = solution(5, [9, 20, 28, 18, 11], [30, 1, 21, 17, 28])
    print(res)


def case_2():
    res = solution(6, [46, 33, 33, 22, 31, 50], [27, 56, 19, 14, 14, 10])
    print(res)


if __name__ == "__main__":
    case_1()
    case_2()
