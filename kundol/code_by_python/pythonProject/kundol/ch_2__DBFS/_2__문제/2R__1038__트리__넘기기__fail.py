N = int(input())
parent_index_list = list(map(int, input().split()))
remove_node_index = int(input())
root_node_index = 0

tree_adj = [[] for _ in range(N)]

for child_index in range(N):
    parent_index = parent_index_list[child_index]
    if parent_index == -1:
        root_node_index = child_index
        continue
    tree_adj[parent_index].append(child_index)


def dfs(node_index):
    global leaf_cnt
    if node_index == remove_node_index:
        return
    children = tree_adj[node_index]
    if len(children) == 0:
        leaf_cnt += 1
    for child in children:
        dfs(child)


leaf_cnt = 0
if root_node_index == remove_node_index:
    print(0)
else:
    dfs(root_node_index)
    print(leaf_cnt)
