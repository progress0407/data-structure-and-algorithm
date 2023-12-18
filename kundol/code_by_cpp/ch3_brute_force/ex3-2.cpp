#include <bits/stdc++.h>

using namespace std;

/**
 * 원복의 필요성
*/

int input_n;
vector<int> adj[10];
int vis[10];

void print(vector<int> route) {
    for(int r: route) cout << r << " ";
    cout << "\n";
}

void go(int here, vector<int> route) {

    vis[here] = 1;
    route.push_back(here);
    cout << "here: " << here << "\n";

    if(route.size() == 3) {
        print(route);
        return;
    }

    for(auto there: adj[here]) {
        if(vis[there]) continue;
        go(there, route);
    }
}

int main() {
    
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[2].push_back(4);
    adj[4].push_back(2);

    vector<int> route;
    go(1, route);

    return 0;
}