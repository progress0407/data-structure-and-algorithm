def find_zeros_in_factorial(n):
    count = 0
    while n >= 5:
        n //= 5
        count += n
    return count

# 입력 받기
T = int(input())

for _ in range(T):
    N = int(input())
    print(find_zeros_in_factorial(N))
