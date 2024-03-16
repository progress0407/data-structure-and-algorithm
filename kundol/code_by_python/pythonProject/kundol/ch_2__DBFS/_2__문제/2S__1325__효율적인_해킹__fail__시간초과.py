# 시간초과

N, M = map(int, input().split())

adj = [[] for _ in range(N + 1)]
vis = [False for _ in range(N + 1)]
cnt_map = {}

for _ in range(M):
    child, parent = map(int, input().split())
    adj[parent].append(child)


def dfs(node_index):
    vis[node_index] = True
    children = adj[node_index]

    cnt = 0
    for child in children:
        cnt += dfs(child)

    return cnt + 1


for i in range(1, N + 1):
    cnt_map[i] = dfs(i)

max_val = max(cnt_map.values())
max_keys = [k for k, v in cnt_map.items() if v == max_val]
max_keys.sort()

print(*max_keys)