N = 4
adj = [[] for _ in range(N + 1)]

adj[1].append(2)
adj[2].extend([3, 4])

for i in range(1, N + 1):
    print(f'{i}: ', end='')
    print(*adj[i])
