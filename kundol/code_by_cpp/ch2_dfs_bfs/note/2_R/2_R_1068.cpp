#include <bits/stdc++.h>

using namespace std;

/**
 * 트리
*/

int n;
int root;
int parent;
int removeNode; // 지울 노드
vector<int> adj[54];

int dfs(int parent) {

    int vis_cnt = 0;
    int child_cnt = 0;

    for(int child : adj[parent]) {

        if(child == removeNode) continue;
        vis_cnt += dfs(child);
        child_cnt++;
    }

    if(child_cnt == 0) return 1;

    return vis_cnt;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int child = 0; child < n; child++) {
        cin >> parent;
        if(parent == -1) root = child;
        else adj[parent].push_back(child);
    }

    cin >> removeNode;

    if(removeNode == root) {
        cout << 0 << "\n";
        return 0;
    }

    cout << dfs(root) << "\n";
    return 0;
}
