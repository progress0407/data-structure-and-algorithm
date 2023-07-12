#include<bits/stdc++.h>

using namespace std;

vector<int> v = {1, 2, 3};

int n = 3;
int r = 3;

void printPermutation(int depth) {

    if (r == depth) {
        for (int i = 0; i < r; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = depth; i < n; i++) {
        swap(v[i], v[depth]);
        printPermutation(depth + 1);
        swap(v[i], v[depth]);
    }
}

int main() {


    printPermutation(0);

    return 0;
}
