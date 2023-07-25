#include <bits/stdc++.h>

using namespace std;

/**
 * 효율적인 해킹
 * 
 * 1. 입력받고 우선은 트리구조로 만들어야 한다
 * 
 * 2. 모든 컴퓨터 N에 대해 순회를 한다
 * 
 * 3. 순회를 하면서 DFS로 각 컴터에 대한 노드의 개수를 카운트한다
 * 
 * 4. {컴퓨터 넘버, 총 노드 개수}를 구조체에 담는다
 * 
 * 5. 커스텀 Comparator로 정렬한다
 * 
 * 6. 가장 큰 노드 개수에 해당하는 컴퓨터 개수 출력, 하나일 경우 하나, 여러개 일경우 컴퓨터 넘버순 오름 차순
*/

int n; // 노드 No <= 만
int m; // 관계의 수 <= 10만
int child;
int parent;
int mx = -1;
int cnt;
int node[10004]; 
int visited[10004]; 
vector<int> tree[100000];

int dfs(int here) {

    int cnt = 1;
    visited[here] = 1;

    if(tree[here].empty()) return 1; // leaf node

    for(int& there : tree[here]) {

        if(visited[there]) continue;

        cnt += dfs(there);
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> child >> parent;
        tree[parent].push_back(child);
    }

    vector<int> cnt_to_nodes[n+4];
    for(int node=1; node<= n; node++)  {
        cnt = dfs(node);
        cnt_to_nodes[cnt].push_back(node);
        mx = max(cnt, mx);
        memset(visited, 0, sizeof(visited));
    }
    
    vector<int> ret = cnt_to_nodes[mx]; // 들어간 순서 자체가 이미 정렬돼 있으므로 굳이 재정렬을 할 필요는 없어 보인다
    // sort(ret.begin(), ret.end());
    
    for(int& e: ret) cout << e << " ";

    return 0;
}
