#include <bits/stdc++.h>

using namespace std;

/**
 * 원복하지 않으면서 순회하기
*/

int input_n;
vector<int> adj[10];
int vis[10];

void print(vector<int> route) {
    for(int r: route) cout << r << " ";
    cout << "\n";
}

void go(int here, vector<int> route) {

    
    cout << "here: " << here << "\n";
    vis[here] = 1;
    cout << "size: " << route.size() << "\n";

    if(route.size() == 3) {
        print(route);
        return;
    }

    for(auto there: adj[here]) {
        if(vis[there]) continue;

        cout << "there: " << there << "\n";

        vis[there] = 1;
        route.push_back(there);
        
        go(there, route);

        // vis[there] = 0;
        route.pop_back();

        cout << "pop there: " << there << "\n";
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
    
    route.push_back(1);
    go(1, route);

    return 0;
}