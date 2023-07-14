#include <bits/stdc++.h>

using namespace std;

/**
 * 수열
 * 
 * 정렬: 틀린 풀이
 * 정렬하면 안됀다
 */

int N, K;

int main() {

    cin >> N
        >> K;

    int nums[N];
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+N);

    int max=0;
    for(int i=N-1; i >= N-K; i-- ) {
        max+= nums[i];
    }
    cout << max;


    return 0;
}
