import itertools

if __name__ == '__main__':
    items = [1, 2, 3]  # 예제 리스트
    combinations = list(itertools.combinations(items, 2))  # 두 번째 인자는 조합의 크기
    print("Combinations:", combinations)
