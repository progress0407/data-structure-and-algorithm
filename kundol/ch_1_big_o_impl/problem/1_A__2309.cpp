#include<bits/stdc++.h>

using namespace std;

/**
 * 일곱 난장이
 */

int a[9 + 1];
int k = 7;
vector<vector<int>> candidates;
vector<int> result;

void comb(int start, vector<int> v) {

    if (v.size() == k) {
        // 배열에 담는다
        candidates.push_back(v);
        return;
    }

    for (int i = start + 1; i <= 9; i++) {
        v.push_back(a[i]);
        comb(i, v);
        v.pop_back();
    }
}

int main() {

    for (int i = 1; i <= 9; i++) cin >> a[i];

    sort(a + 1, a + 10);

    vector<int> v;
    comb(0, v);

    for (auto c: candidates) {
        int sum = 0;
        for (auto e: c) sum += e;

        if (sum == 100) {
            result = c;
        }
    }

    for (auto e: result) cout << e << "\n";

    return 0;
}


