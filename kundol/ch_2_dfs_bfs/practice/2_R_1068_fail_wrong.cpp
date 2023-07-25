#include <bits/stdc++.h>

using namespace std;

/**
 * 트리
*/

int input_size, parent;
int root;
int node_to_del;
// vector<pair<int, vector<int>>> tree;
// vector<pair<int, int>> tree;
// map<int, int> child_to_parent;
map<int, vector<int>> parent_to_children;

int dfs_node_cnt(int node, int cnt) {

    vector<int> children = parent_to_children[node];

    // cout << "parent: " << node << "\nchildren:  ";
    // for(int& child : children) cout << child << " ";
    // cout << "\n\n";

    if(children.empty()) {
        return 1;
    }

    for(int& child : children) {
        cnt += dfs_node_cnt(child, cnt);
    }


    return cnt;
}

void dfs_remove(int st_node, int remove_node) {

    vector<int>& children = parent_to_children[st_node];

    // remove val
    children.erase(remove(children.begin(), children.end(), remove_node), children.end());

    if(children.empty()) {
        return;
    }

    for(int& child : children) {
        dfs_remove(child, remove_node);
    }
}

int count_leaf_node() {

    return dfs_node_cnt(root, 0);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> input_size;

    // make tree
    for (int child = 0; child < input_size; child++) {
        cin >> parent;
        if(parent == -1) {
            root = child;            
        } else {
            parent_to_children[parent].push_back(child);
        }
    }

    // cout << "leaf node cnt: \n" << count_leaf_node() << "\n";

    cin >> node_to_del;
    // cout<<"node_to_del: "<<node_to_del<<"\n";
    parent_to_children.erase(node_to_del);
    dfs_remove(root, node_to_del);

    cout << count_leaf_node() << "\n";

    return 0;
}
