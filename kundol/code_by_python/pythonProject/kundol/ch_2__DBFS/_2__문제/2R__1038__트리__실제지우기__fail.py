N = int(input())
parent_index_list = list(map(int, input().split()))
remove_node_index = int(input())

tree_adj = [[] for _ in range(N)]

for child_index in range(len(parent_index_list)):
    parent_index = parent_index_list[child_index]
    if parent_index == -1:
        continue
    tree_adj[parent_index].append(child_index)


def dfs(remove_node_index):
    global tree_adj
    children = tree_adj[remove_node_index]
    if len(children) == 0:
        tree_adj.pop(remove_node_index)
    else:
        # 상대적으로 작은수부터 제거하면, index가 꼬인다
        # 3지우고 4지울시에,
        # 인접리스트 총 길이가 줄어들면서 인덱스도 바뀌게 된다, 따라서, 큰 숫자부터 지운다
        children.sort()
        children.reverse()
        for child in children:
            dfs(child)


dfs(remove_node_index)

leaf_cnt = 0
for tree_element in tree_adj:
    if len(tree_element) == 0:
        leaf_cnt += 1

print(leaf_cnt)
