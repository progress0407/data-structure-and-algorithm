#include <bits/stdc++.h>

using namespace std;

/**
 * 트리
*/

int n;
int root;
int removeNode; // 지울 노드
vector<int> adj[54];

int dfs(int parent, int removeNode) {

    if(removeNode == root) {
        return 0;
    }

    if(parent == removeNode) { // 지울 노드는 방문하지 않음, 실제로 지운 것은 아니나 이렇게 하면 정답과 동일하다
        return 0;
    }

    int vis_cnt = 0;

    if(adj[parent].empty()) { // parent 노드가 리프 노드일 경우
        return 1;
    }

    for(auto& child : adj[parent]) {
        vis_cnt += dfs(child, removeNode);
    }

    return vis_cnt;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int child = 0; child < n; child++) {
        int parent;
        cin >> parent;
        if(parent == -1) {
            root = child;
        } else {
            adj[parent].push_back(child);
        }
    }

    cin >> removeNode;

    cout << dfs(root, removeNode) << "\n";
    
    return 0;
}
