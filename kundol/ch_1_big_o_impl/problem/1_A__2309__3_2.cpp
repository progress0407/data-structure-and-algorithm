#include<bits/stdc++.h>

using namespace std;

/**
 * 일곱 난장이
 * 조합 9 C 7 == 9 C 2
 *
 * vector 특정 원소 제거를 index로
 */

int n = 9;
vector<int> v;

int main() {


    for (int i = 1; i <= n; i++) {
        int in;
        cin >> in;
        v.push_back(in);
    }

    int allSum = 0;
    for (int e: v) allSum += e;

    vector<int> ex;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            int subSum = v[i] + v[j];
            if (allSum - subSum == 100) {
                ex.push_back(i);
                ex.push_back(j);
            }
        }
    }

    for (int idx: ex) {
        v.erase(v.begin() + idx);
    }

    sort(v.begin(), v.end());

    for (int e: v) cout << e << "\n";

    return 0;
}


