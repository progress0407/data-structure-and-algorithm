#include <bits/stdc++.h>

using namespace std;

/**
 * 주몽
 */

int N, M;
vector<int> ori_v;
int result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N
        >> M;

    ori_v.resize(N);
    for (auto &e: ori_v) cin >> e;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int sum = ori_v[i] + ori_v[j];
            if (sum == M) result++;
        }
    }

    cout << result;

    return 0;
}
