import itertools


if __name__ == "__main__":
    # data = list(map(int, input().split()))
    # print(data)

    # a,b,c = map(int, input().split())
    # print(f"a, b, c = {a, b, c}")

    # res = [1,2,3]
    # print(*res)

    # vis = [[False] * 3 for _ in range(3)]
    # print(vis)

    # print([1 for _ in range(3)])

    # n_arr = [n * 3 for n in [1,2,3]]
    # print(*n_arr)

    arr = itertools.combinations([1, 2, 3], 2)
    for v in arr:
        print(*v)
