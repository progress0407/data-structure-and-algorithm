n = 4
adj = [[] for _ in range(n)]

adj[0].extend([1, 2, 3])
adj[1].extend([0, 2])
adj[2].extend([0, 3])
adj[3].extend([2])

for i in range(len(adj)):
    print(f'{i} :: ', end='')
    for j in adj[i]:
        print(f'{j} ', end='')
    print()
