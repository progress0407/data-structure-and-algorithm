#include<bits/stdc++.h>

using namespace std;
int arr[3] = {1, 2, 3};
int n = 3;
int r = 3;

void print(int arr[]) {
    for (int i = 0; i < r; i++) cout << arr[i] << " ";
    cout << '\n';
}

void makePermutation(int depth) {

    // 포인트 2:: 종료 조건
    if (r == depth) {
        print(arr);
        return;
    }

    // 포인트 3:: for문 i 첨자
    for (int i = depth; i < n; i++) {
        swap(arr[i], arr[depth]);
        makePermutation(depth + 1);
        swap(arr[i], arr[depth]); // 원복
    }
}

int main() {

    makePermutation(0); // 포인트 1

    return 0;
}

