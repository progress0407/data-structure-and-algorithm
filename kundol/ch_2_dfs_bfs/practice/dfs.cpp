#include<bits/stdc++.h>

using namespace std;

const int n = 6;
vector<int> adj[n];
bool visited[n];

void dfs_1(int u) {
    visited[u] = true;
    cout << u << '\n';
    for (auto v: adj[u]) {
        if (visited[v]) continue;
        dfs_1(v);
    }
    return;
}

void dfs_2(int u) {
    if (visited[u]) return;
    visited[u] = true;
    cout << u << '\n';
    for (auto v: adj[u]) {
        dfs_2(v);
    }
    return;
}


int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);

    // 돌다리
//    dfs_1(1);

    // 일단 go
    dfs_2(1);
}
/*
1
2
4
4로부터 시작된 함수가 종료되었습니다.
5
5로부터 시작된 함수가 종료되었습니다.
2로부터 시작된 함수가 종료되었습니다.
3
3로부터 시작된 함수가 종료되었습니다.
1로부터 시작된 함수가 종료되었습니다.
*/

