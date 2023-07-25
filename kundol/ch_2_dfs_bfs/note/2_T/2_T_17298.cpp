#include <bits/stdc++.h>

using namespace std;

#define prev aaa

/**
 * 오큰수
 * 
 * 입력을 받을떄마다 갱신한다...?
*/

int in_n;
int a[1000004];
int n[1000004];

stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    memset(n, -1, sizeof(n));

    cin >> in_n;

    cin >> a[1]; 
    stk.push(1);

    for (int i = 2; i <= in_n; i++) {
        cin >> a[i];

        while(!stk.empty() && a[stk.top()] < a[i]) {
            int lastIdx = stk.top();
            n[lastIdx] = a[i];
            stk.pop();
        }

        stk.push(i);
    }

    for (int i = 1; i <= in_n; i++) {
        cout << n[i] << " ";
    }

    return 0;
}
