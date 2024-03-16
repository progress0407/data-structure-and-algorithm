from sys import setrecursionlimit

N, M = map(int, input().split())

setrecursionlimit(N * N + 4)

adj = [[] for _ in range(N + 1)]
vis = [0 for _ in range(N + 1)]


def dfs(node_index):
    vis[node_index] = 1
    children = adj[node_index]
    # 여기서 child는 index겸 value
    for child in children:
        if vis[child] == 0:
            vis[node_index] += dfs(child)
        else:
            vis[node_index] += vis[child]
    return vis[node_index]


for _ in range(M):
    child, parent = map(int, input().split())
    adj[parent].append(child)

max_cnt = 0
for node_index in range(1, N + 1):
    if vis[node_index] > 0:
        continue
    cur_cnt = dfs(node_index)
    max_cnt = max(max_cnt, cur_cnt)

for node_index in range(1, N + 1):
    node_cnt = vis[node_index]
    if node_cnt == max_cnt:
        print(f'{node_index}', end=' ')
