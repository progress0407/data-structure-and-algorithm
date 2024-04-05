# a^b mod m

# 단순 풀이
# def some_fn(a, b, m):
#     return a ** b % m

def some_fn(a, b, m):
    res = 1
    for b in range(b):
        res *= (res * a) % m
    return res


if __name__ == '__main__':
    res = some_fn(5, 2, 4)
    # res = some_fn(6, 100, 5)
    print(res)
