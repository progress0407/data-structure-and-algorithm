# 주어진 문자열
s = """101
110"""

# 문자열을 줄 단위로 분리한 후, 각 문자를 정수로 변환하여 2차원 리스트로 저장
result = [list(map(int, line)) for line in s.split('\n')]

print(result)
