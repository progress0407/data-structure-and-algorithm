#include <bits/stdc++.h>

using namespace std;
int from, to, n, idx = 0, ret = 1;  

/**
 * 회의실 배정
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    vector<pair<int, int>> v; 

    for(int i = 0; i < n; i++){
        cin >> from >> to;
        v.push_back({to, from}); 
    }

    sort(v.begin(), v.end()); 

    // to: first,  from: second

    stack<int> stk;
    stk.push(v[0].first);
    int cnt = 1;

    for(int i=1; i<v.size(); i++) {
        auto before = stk.top();
        auto targetFrom= v[i].second; // 뒤 노드의 앞
        if(before <= targetFrom) { 
            stk.push(v[i].first); // 뒤 노드의 뒤
            cnt++;
        }
    }

    cout << cnt << "\n";
    

    return 0;
}

