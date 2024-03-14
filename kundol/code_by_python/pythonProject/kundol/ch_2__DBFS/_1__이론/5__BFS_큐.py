from collections import deque

adj = [[] for _ in range(100)]
vis = [0 for _ in range(100)]
adj[10].extend([12, 14, 16])
adj[12].extend([18, 20])
adj[20].extend([22, 24])

que = deque()
que.append(10)

while len(que) > 0:
    here = que.popleft()
    vis[here] = 1
    print(here)
    for there in adj[here]:
        if vis[there] == 0:
            que.append(there)