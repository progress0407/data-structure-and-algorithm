import re

n = int(input())

li = []
for _ in range(n):
    str = input()
    numbers = re.findall(r'\d+', str)
    li.extend(map(int, numbers))

sort = li.sort()
for v in li:
    print(v)