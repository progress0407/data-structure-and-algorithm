from collections import deque

adj = [[] for _ in range(100)]
vis = [0 for _ in range(100)]
adj[10].extend([12, 14, 16])
adj[12].extend([18, 20])
adj[20].extend([22, 24])

que = deque()
que.append(10)
vis[10] = 1

while len(que) > 0:
    here = que.popleft()
    for there in adj[here]:
        if vis[there] == 0:
            que.append(there)
            vis[there] = vis[here] + 1 # 이게 이 위치에 있어야 거리를 표시할 수 있다!

print(vis[24])
