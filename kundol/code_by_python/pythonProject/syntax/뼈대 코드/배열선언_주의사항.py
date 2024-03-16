# 이렇게 하면 얕은 카피로 인해 문제가 생김
def case_1():
    arr = [[]] * 5
    arr[0].append(100)
    print(arr)


# 깊은 복사, 이렇게 해야 한다
def case_2():
    arr = [[] for _ in range(5)]
    arr[0].append(100)
    print(arr)


if __name__ == "__main__":
    case_1()
    case_2()
