#include <bits/stdc++.h>

using namespace std;

/**
 * 오큰수
 * 
 * 푸는데 너무 쉬웠다... 아니나 다를까 시간초과!
*/

int in_n;
int a[1000004];
int n[1000004];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> in_n;
    for (int i = 1; i <= in_n; i++) {
        cin >> a[i];
    }

    for(int i=1; i< in_n; i++) {
        for (int j = i; j <= in_n; j++) {
            if(a[i] < a[j]) {
                n[i] = a[j];
                break;
            }
            if(j==in_n && !(a[i] < a[j])) { //  마지막에 왔는데 큰 수를 찾지 못했다면
                n[i] = -1;
            }
        }
    }
    n[in_n] = -1;
    
    for (int i = 1; i <= in_n; i++) cout << n[i] << " ";
    cout << "\n";

    return 0;
}
