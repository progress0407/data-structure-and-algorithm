#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int visited[100];

void bfs(int init) {
    queue<int> q;
    q.push(init);
    visited[init] = 1;

    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (auto to: adj[here]) {
            if (visited[to]) continue;
            q.push(to);
            visited[to] = visited[here] + 1;
        }
    }
}

int main() {
    // given
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);

    // when
    bfs(10);

    // then
    for (int i: {10, 12, 14, 16, 18, 20, 22, 24}) { // node list
        cout << i << " : " << visited[i] << '\n';
    }

    cout << "distance of 10 and 24" << visited[24] - 1 << '\n';

    return 0;
}
/**
10 : 1
12 : 2
14 : 2
16 : 2
18 : 3
20 : 3
22 : 4
24 : 4
10번으로부터 24번까지 최단거리는 : 3
*/
