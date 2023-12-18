#include<bits/stdc++.h>

using namespace std;

/**
 * 2차원 배열도 조합으로 해결할 수 있는가?
*/

int n = 4, r = 2;
vector<pair<int, int>> pairs = {
    {1, 2}, {2, 3}, {3, 4}, {4, 5}
};

void print(vector<pair<int, int>> v) {
    for (auto& e : v) cout << e.first << ":" << e.second << " ";
    cout << "\n";
}

void combi(int st, vector<pair<int, int>> v) {

    if (v.size() == r) {
        print(v);
        return;
    }

    for (int i = st + 1; i < n; i++) {
        v.push_back(pairs[i]);
        combi(i, v);
        v.pop_back();
    }
}

int main() {

    vector<pair<int, int>> v;
    combi(-1, v);

    return 0;
}