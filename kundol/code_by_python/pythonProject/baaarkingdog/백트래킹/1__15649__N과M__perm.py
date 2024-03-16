from itertools import permutations

n, m = map(int, input().split())

num_list = [i + 1 for i in range(n)]

perm_list = list(permutations(num_list, m))

for perm in perm_list:
    print(*perm)
