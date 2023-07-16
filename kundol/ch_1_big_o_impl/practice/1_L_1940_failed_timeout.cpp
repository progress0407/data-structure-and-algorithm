#include <bits/stdc++.h>

using namespace std;

/**
 * 주몽
 */

int N, M;
vector<int> ori_v;
int result = 0;

void combi(vector<int> v, int depth) {

    if (v.size() == 2) {
        int sum = v[0] + v[1];

        if (sum == M) {
            result++;
        }

        return;
    }

    for (int i = depth + 1; i < N; i++) {
        v.push_back(ori_v[i]);
        combi(v, i);
        v.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N
        >> M;

    ori_v.resize(N);
    for(auto &e : ori_v) cin >> e;

    vector<int> v;
    combi(v, -1);
    cout << result;

    return 0;
}
