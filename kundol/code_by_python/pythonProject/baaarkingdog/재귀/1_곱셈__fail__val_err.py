import sys

a, b, c = map(int, input().split())
sys.setrecursionlimit(b // 2)


# n: 곱할 횟수
def recur_mul(n):
    if n == 1:
        return a % c
    val = recur_mul(n // 2)
    if n % 2 == 0:
        return (val * val) % c
    else:
        return (val * val * a) % c


res = recur_mul(b)
print(res)
