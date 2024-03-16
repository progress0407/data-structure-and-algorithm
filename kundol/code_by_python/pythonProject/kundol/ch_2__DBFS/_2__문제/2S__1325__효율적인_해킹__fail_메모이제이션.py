# Runtime Error, Key Error
N, M = map(int, input().split())

# index == value 가 되도록 데이터 초기화
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
        if not vis[child]:
            cnt += dfs(child)
        else:
            cnt += cnt_map[child]

    cnt_map[node_index] = cnt + 1
    return cnt_map[node_index]

max_cnt=0
max_nodes = []
for node_index in range(1, N + 1):
    cur_cnt = dfs(node_index)
    max_cnt = max(max_cnt, cur_cnt)
    if max_cnt < cur_cnt:
        max_cnt = cur_cnt
        max_nodes.clear()
    elif cur_cnt == max_cnt:
        max_nodes.append(node_index)

max_nodes.sort()

print(*max_nodes)