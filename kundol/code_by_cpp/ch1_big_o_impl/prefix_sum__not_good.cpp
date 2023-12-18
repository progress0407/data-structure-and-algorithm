#include<bits/stdc++.h>

using namespace std;

int a[10004], n, m;
vector<int> psum;

int main() {

    cin >> n >> m;

//    cout << "n: " << n << "\n";
//    cout << "m: " << m << "\n";

    for (int i=1; i <= n; i++) {
        cin >> a[i];
    }

     vector<pair<int, int>> pair_list;
     for (int i = 0; i < m; ++i) {
         int st, ed;
         cin >> st >> ed;

         pair<int, int> p = make_pair(st, ed);
         pair_list.push_back(p);
     }

    vector<int> res;
    for (auto e : pair_list) {
        int s = 0;
        for(int i = e.first; i <= e.second ; ++i) s += a[i];
        psum.push_back(s);
    }

    for (auto e : psum) {
        cout << e << "\n";
    }

    return 0;
}