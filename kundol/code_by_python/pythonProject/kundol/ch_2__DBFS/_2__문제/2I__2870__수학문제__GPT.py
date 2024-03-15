import re

# 입력 받기
N = int(input())
lines = [input() for _ in range(N)]

# 숫자 찾기
numbers = []
for line in lines:
    # 정규 표현식으로 숫자 찾기
    found_numbers = re.findall(r'\d+', line)
    # 찾은 숫자를 정수로 변환하여 numbers 리스트에 추가
    numbers.extend(map(int, found_numbers))

# 숫자들을 비내림차순으로 정렬
numbers.sort()

# 숫자 출력
for number in numbers:
    print(number)
