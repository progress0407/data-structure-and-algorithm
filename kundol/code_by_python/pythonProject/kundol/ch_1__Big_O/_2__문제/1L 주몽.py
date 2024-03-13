import itertools
import sys

n = int(input())
m = int(input())
li = list(map(int, input().split()))

if m > 200000:
    print(0)
    sys.exit(0)

combinations = list(itertools.combinations(li, 2))

cnt = 0
for combination in combinations:
    if sum(combination) == m:
        cnt += 1

print(cnt)
