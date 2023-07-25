#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, vector<int>> x;
    x[0].push_back(10);
    x[0].push_back(20);

    auto children = x[0];

    for(auto& e: children) cout << e << " ";


    return 0;
}
