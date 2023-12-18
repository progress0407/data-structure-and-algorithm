#include<bits/stdc++.h>

using namespace std;

int N = 3;
int R = 3;

int arr[3 + 1] = {0, 1, 2, 3};

void print(int arr[]) {
    for (int i = 1; i <= R; i++) cout << arr[i] << " ";
    cout << '\n';
}

void makePermutation(int depth) {

    // 포인트 2:: 종료 조건
    if (R == depth) {
        print(arr);
        return;
    }

    // 포인트 3:: for문 i 첨자
    for (int i = depth; i <= N; i++) {
        swap(arr[i], arr[depth]);
        makePermutation(depth + 1);
        swap(arr[i], arr[depth]); // 원복
    }
}

int main() {

    makePermutation(1); // 포인트 1

    return 0;
}

