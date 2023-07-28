#include <bits/stdc++.h>

using namespace std;

/**
 * 나는야 포켓몬 마스터 이다솜
 */

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N
        >> M;

    string num_to_alp[N + 1];
    map<string, int> alp_to_num;
    for (int i = 1; i <= N; i++) {
        string poke_name;
        cin >> poke_name;
        num_to_alp[i] = poke_name;
        alp_to_num[poke_name] = i;
    }

    vector<string> problems;
    problems.resize(M);
    for (auto &e: problems) {
        cin >> e;
    }

    for (string problem: problems) {
        if (problem[0] >= '0' && problem[0] <= '9') { // 숫자인 경우
            cout << num_to_alp[stoi(problem)] << '\n';
        } else { // 문자인 경우
            cout << alp_to_num[problem] << '\n';
        }
    }

    return 0;
}
