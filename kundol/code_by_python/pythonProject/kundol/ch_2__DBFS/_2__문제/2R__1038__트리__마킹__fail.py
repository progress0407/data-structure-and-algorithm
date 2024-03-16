N = int(input())
parent_index_list = list(map(int, input().split()))
remove_node_index = int(input())

# tree_adj[*][0]: 삭제 여부
# tree_adj[*][1]: 자식 리스트
tree_adj = [[False, []] for _ in range(N)]

for child_index in range(len(parent_index_list)):
    parent_index = parent_index_list[child_index]
    if parent_index == -1:
        continue
    tree_adj[parent_index][1].append(child_index)


def dfs(remove_node_index):
    id_del = tree_adj[remove_node_index][0]
    if id_del:
        return
    children = tree_adj[remove_node_index][1]
    if len(children) == 0:
        tree_adj[remove_node_index][1].clear()
        tree_adj[remove_node_index][0] = True
    else:
        for child in children:
            dfs(child)


dfs(remove_node_index)

leaf_cnt = 0
for tree_tuple in tree_adj:
    is_del = tree_tuple[0]
    if is_del:
        continue
    children = tree_tuple[1]
    if len(children) == 0:
        leaf_cnt += 1

print(leaf_cnt)
