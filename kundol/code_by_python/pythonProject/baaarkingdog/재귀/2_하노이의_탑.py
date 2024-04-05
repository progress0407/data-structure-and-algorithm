cnt = 0


def hanoi(k, pos):
    global cnt
    cnt += 1
    if k == 1:
        return
    if pos == 1:
        hanoi(k-1, 2)
    elif pos == 2:
        hanoi(k - 1, 1)


if __name__ == '__main__':
    n = int(input())
    hanoi(n, 1)
    print(cnt)
