#include<bits/stdc++.h>

using namespace std;

/**
 * 트럭 주차
 */

int a, b, c;
int t[101];

map<int, int> p_m; // 요금
map<int, int> t_m; // 시간

int main() {

    cin >> a >> b >> c;
    p_m[1] = a;
    p_m[2] = 2 * b;
    p_m[3] = 3 * c;

    vector<pair<int, int>> st_ed_list;
    for (int i = 0; i < 3; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        st_ed_list.push_back(p);
    }

    for (auto e: st_ed_list) {
        int st = e.first;
        int ed = e.second;

        for (int i = st; i < ed; i++) {
            t[i]++;
        }
    }

    for (int i = 1; i < 101; i++) {
        if(t[i] == 0) continue;
        t_m[t[i]]++;
    }

    int tot_price = 0;
    for (int i = 1; i <= 3; i++) {
        tot_price += t_m[i] * p_m[i];
    }

    cout << tot_price;

    return 0;
}
