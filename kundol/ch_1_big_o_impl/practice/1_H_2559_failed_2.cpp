#include <bits/stdc++.h>

using namespace std;

/**
 * 수열
 * 
 * 이번엔 시간초과가 아닌 틀렸음
 */

int N, K;

int main() {

    cin >> N
        >> K;

    int nums[N];

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int s[N];
    s[0] = nums[0];
    int d[N]; // 1 미사용

    for(int i=1; i<N; i++) {
        s[i] = s[i-1] + nums[i];
    }


    d[1] = s[1];
    for(int i=K;i<N;i++) {
        d[i] = s[i] - s[i-K];
    }

    int max= 0;
    for(int i=K;i<N;i++) {
        if(max < d[i]) max = d[i];
    }

    cout << max;


    return 0;
}
