#include<bits/stdc++.h>

using namespace std;

/**
 * 일곱 난장이
 * 조합 9 C 7 == 9 C 2
 *
 * pair 이용
 */

int n = 9;
vector<int> v;

int main() {


    for (int i = 1; i <= n; i++) {
        int in;
        cin >> in;
        v.push_back(in);
    }

    sort(v.begin(), v.end());

    int allSum = 0;
    for (int e: v) allSum += e;

    pair<int, int> ex;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            int subSum = v[i] + v[j];
            if (allSum - subSum == 100) {
                ex = {i, j};
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if( ex.first == i || ex.second == i) continue;
        cout << v[i] << "\n";
    }

    return 0;
}


