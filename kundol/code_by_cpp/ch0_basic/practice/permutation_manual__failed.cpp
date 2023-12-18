#include<bits/stdc++.h>

using namespace std;

/**
 * 내가 수정한 버전
 *
 * fail
 * 교훈: 그냥 외워야 한다...
 */

vector<int> v{1, 2, 3};
int n = 3;
int r = 3;

void printV(vector<int> &v) {
    for (int i = 0; i < r; i++) cout << v[i] << " ";
    cout << "\n";
}

void makePermutation(int depth) {

    if (r == depth) {
        return;
    }

    for (int i = depth + 1; i < n; i++) {
        swap(v[i], v[depth]);
        makePermutation(depth + 1);
        swap(v[i], v[depth]); // 원복
    }

    printV(v);
}

int main() {

    makePermutation(0);

    return 0;
}

