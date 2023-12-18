#include <bits/stdc++.h>

using namespace std;

/**
 * 두 수의 합
*/

int n, x, cnt;
int a[1000000];

void check(int i, int j) {
    if(a[i] + a[j] == x) {
        cnt++;
        // printf("(%d, %d)\n",a[i],a[j]);
    }
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> x;

    for(int i=0; i <= n-1; i++) {
        for(int j=n-1; i<=j; j--) {
            check(i, j);
            // printf("i, j = (%d, %d)\n", i, j);
        }
    }

    cout << cnt << '\n';

    return 0;
}

