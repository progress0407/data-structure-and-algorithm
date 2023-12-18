#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a = {1, 2, 3};
    do {
        for (int e: a) cout << e << " ";
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}



