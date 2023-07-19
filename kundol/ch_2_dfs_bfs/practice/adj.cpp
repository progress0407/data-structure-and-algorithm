#include<bits/stdc++.h>

using namespace std;
const int V = 4;
vector<int> adj[V];

int main() {
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);

    adj[2].push_back(0);
    adj[2].push_back(1);

    adj[3].push_back(0);

    cout << "[first section]\n";

    for (int i = 0; i < 4; i++) {
        cout << i << " :: ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << "\n[second section]\n";
    for (int i = 0; i < 4; i++) {
        cout << i << " :: ";
        for (auto e: adj[i]) {
            cout << e << ' ';
        }
        cout << '\n';
    }

}
/*
0 :: 1 2 3
1 :: 0 2
2 :: 0 1
3 :: 0
*/
