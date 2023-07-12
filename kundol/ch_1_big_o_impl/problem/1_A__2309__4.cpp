#include<bits/stdc++.h>

using namespace std;

/**
 * 일곱 난장이
 *
 * 큰돌님 풀이
 * 수동 작성 순열 + exit(0)
 * sorting을 하지 않으면 너무 많은 연산을 한다
 */

int N = 9;
int R = 7;
int arr[9 + 1];

int cnt =0;
void doPermutation(int depth) {

    if (R == depth) {
        cout << "cnt : " << ++cnt << '\n';

        // 완성된 배열
        int sum = 0;
        for (int i = 1; i <= R; i++) {
            sum += arr[i];
        }
        if (sum == 100) {
            sort(arr + 1, arr + R + 1);
            for (int i = 1; i <= R; i++) cout << arr[i] << '\n';
            exit(0);
        }
        return;
    }

    for (int i = depth; i <= N; i++) {
        cout << "i : " << i << '\n';
        cout << "depth : " << depth << '\n';

        swap(arr[i], arr[depth]);
        doPermutation(depth + 1);
        swap(arr[i], arr[depth]);
    }
}

int main() {

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    int depth = 1;
    doPermutation(depth);

    return 0;
}


