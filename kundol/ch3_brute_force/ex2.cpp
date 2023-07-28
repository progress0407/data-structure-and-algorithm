#include <bits/stdc++.h>

using namespace std;

/**
 * made by 큰돌] 승철이의 문단속
*/

int input_n;
int a[104];
int cnt;

bool isPrimeNum(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;

    for(int i=2; i*i<= n; i++)
        if(n%i == 0) return false;

    return true;
}

void dfs(int idx, int sum) {

    
    if (idx == input_n - 1) {
        if (isPrimeNum(sum)) 
            cnt++;
        return;
    }

    dfs(idx + 1, sum + a[idx+1]);
    dfs(idx + 1, sum);
}

int main() {
    
    cin >> input_n;

    for (size_t i = 0; i < input_n; i++)
        cin >> a[i];
    
    dfs(0, a[0]);
    dfs(0, 0);
    
    cout << cnt << "\n";

    return 0;
}