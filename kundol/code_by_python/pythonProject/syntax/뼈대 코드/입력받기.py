# 스페이스바로 띠워진 숫자 입력 받기 ex) 1 2 3 4 5 6 7 ...
def case_1():
    nums = list(map(int, input().split()))


# 스페이스바로 띠워진 적은 숫자 입력 받기 ex)1 2
def case_2():
    N, M = map(int, input().split())


# 2차원 배열 형태로 입력받기
def case_3():
    N = 10
    mapp = [list(map(int, input().split())) for _ in range(N)]


if __name__ == "__main__":
    case_1()
    case_2()
    case_3()
