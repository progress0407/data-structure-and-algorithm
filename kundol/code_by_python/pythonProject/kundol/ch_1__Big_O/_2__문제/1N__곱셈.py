# 교훈: 재귀를 이용한 풀이, 짝/홀 구분하기
# 나머지 연산은 아무대나 무식하게 때려도 연산량에는 큰 영향이 없다

a, b, c = map(int, input().split())


def recur(a, b):
    if b == 1:
        return a % c

    if b % 2 == 0:
        res = recur(a, b // 2) % c
        return res * res % c
    else:
        res = recur(a, b // 2)
        return res * res * a % c
    pass


res = recur(a, b) % c
print(res)
