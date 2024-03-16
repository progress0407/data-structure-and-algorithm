T = int(input())  # 테스트 케이스의 수

for _ in range(T):
    ps = input()  # 괄호 문자열 입력
    count = 0  # 괄호의 균형을 확인하기 위한 카운터

    for char in ps:
        if char == '(':
            count += 1
        else:
            count -= 1
            if count < 0:  # 닫는 괄호가 더 많아진 경우
                break

    if count == 0:
        print("YES")
    else:
        print("NO")