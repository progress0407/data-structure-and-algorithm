import itertools
import sys

n = int(input())
m = int(input())
li = list(map(int, input().split()))

if m > 200000:
    print(0)
    sys.exit(0)

combinations = list(itertools.combinations(li, 2))

one_loop_area = 0
for combination in combinations:
    if sum(combination) == m:
        one_loop_area += 1

print(one_loop_area)
