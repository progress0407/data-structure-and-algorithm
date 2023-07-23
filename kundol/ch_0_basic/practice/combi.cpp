#include<bits/stdc++.h>

using namespace std;

int n = 5, r = 3;
int a[5] = {1, 2, 3, 4, 5};

void print(vector<int> v) {
    for (int e: v) cout << e << " ";
    cout << "\n";
}

void combi(int st, vector<int> v) {

    if (v.size() == r) {
        print(v);
        return;
    }

    for (int i = st + 1; i < n; i++) {
        v.push_back(a[i]);
        combi(i, v);
        v.pop_back();
    }
}

int main() {

    vector<int> v;
    combi(-1, v);

    return 0;
}