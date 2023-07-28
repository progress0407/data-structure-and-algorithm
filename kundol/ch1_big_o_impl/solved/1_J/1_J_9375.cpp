#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;


    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        map<string, int> mp;
        for (int j = 0; j < m; j++) {
            string v, k;
            cin >> v >> k;
            mp[k]++;
        }

        // 계산
        if (mp.size() == 1) {
            cout << mp.begin()->second << '\n';
        } else {
            int sum = 1;
            for (auto e: mp) {
                sum *= (e.second + 1);
            }
            cout << sum - 1 << '\n';
        }
    }

    return 0;
}
