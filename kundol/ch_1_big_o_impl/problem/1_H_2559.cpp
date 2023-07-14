#include <bits/stdc++.h>

using namespace std;

/**
 * 수열
 * 
 */

int N, K, ret=-10000004, psum[100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N
        >> K;

    int a[N];
    for (int i = 0; i < N; i++) cin >> a[i];

    psum[0] = a[0];
    for (int i = 1; i < N; i++) psum[i] = psum[i-1] + a[i];

    ret = psum[K-1];
    for (int i = K; i < N; i++) {
        ret = max(ret, psum[i] - psum[i - K]);
    }

    cout << ret;

    return 0;
}
