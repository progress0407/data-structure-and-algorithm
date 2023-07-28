#include <bits/stdc++.h>

using namespace std;

/**
 * 수열
 * 
 * 실패 요인: 시간 초과: N^2
 * N으로 풀어보자
 */

int N, K;

int main() {

    cin >> N
        >> K;

    int nums[N];

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int max = -1;
    for (int i = 0; i <= N - K; i++) {
        int sum = 0;
        for (int j = i; j < i + K; j++) {
            sum += nums[j];
        }
        if (max < sum) {
            max = sum;
        }
    }

    cout << max;

    return 0;
}
