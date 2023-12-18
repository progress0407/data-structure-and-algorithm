#include<bits/stdc++.h>
using namespace std;
const int V = 4;

vector<int> adj[V];

int main(){
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);

    adj[2].push_back(0);
    adj[2].push_back(1);

    adj[3].push_back(0);

    cout << "hello world" << "\n";

    for (int here = 0; here < 4; here++) {
        cout << here << " :: ";
        for(int& node: adj[here]) {
            cout << node << " ";
        }
        cout << "\n";
    }
    

}

/*
0 :: 1 2 3
1 :: 0 2
2 :: 0 1
3 :: 0
*/
