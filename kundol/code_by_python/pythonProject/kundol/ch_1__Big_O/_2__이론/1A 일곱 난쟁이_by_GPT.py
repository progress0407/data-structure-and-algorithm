from itertools import combinations

def print_answer(ints):
    for i in sorted(ints):
        print(i)

if __name__ == "__main__":
    # 9개의 숫자 입력 받기 (예시 입력으로 대체)
    arr = [int(input()) for _ in range(9)]

    # 7개의 숫자 조합 생성
    list_combinations = combinations(arr, 7)

    # 합이 100이 되는 조합 찾기
    for ints in list_combinations:
        if sum(ints) == 100:
            print_answer(ints)
            break  # 정답이 유일하다고 가정하고 찾으면 바로 종료

