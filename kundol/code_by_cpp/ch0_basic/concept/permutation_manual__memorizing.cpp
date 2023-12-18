#include<bits/stdc++.h>

using namespace std;
vector<int> v = {1, 2, 3};
int n = 3;
int r = 2;

void printV(vector<int> &v) {
    for (int i = 0; i < r; i++) cout << v[i] << " ";
    cout << "\n";
}

void makePermutation(int depth) {

    // 포인트 2:: 종료 조건
    if (r == depth) {
        printV(v);
        return;
    }

    // 포인트 3:: for문 i 첨자
    for (int i = depth; i < n; i++) {
        swap(v[i], v[depth]);
        makePermutation(depth + 1);
        swap(v[i], v[depth]); // 원복
    }
}

int main() {

    makePermutation(0); // 포인트 1

    return 0;
}

