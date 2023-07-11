#include<bits/stdc++.h>

using namespace std;

int n, m, a[1004];
vector<pair<int, int>> pl;
vector<int> psum;

int main() {

    // input
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        pl.push_back(p);
    }

    // calc
    for (auto p: pl) {
        int st = p.first;
        int ed = p.second;
        int s = 0;
        for (int i = st; i <= ed; i++) s += a[i];
        psum.push_back(s);
    }

    // print
    for (auto s: psum) cout << s << "\n";

    return 0;
}