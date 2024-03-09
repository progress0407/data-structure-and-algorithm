import itertools


input_nums = [int(input()) for _ in range(9)]

candis = itertools.combinations(input_nums, 7)

for candi in candis:
    s = sum(candi)
    if s == 100:
        for v in sorted(candi):
            print(v)
        break

