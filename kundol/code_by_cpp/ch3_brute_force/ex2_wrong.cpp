#include <bits/stdc++.h>

using namespace std;

/**
 * made by 큰돌] 승철이의 문단속
 * 
 * 틀렸지만 교훈이 있다...
 * 이렇게 풀면 틀리는데, 이 틀린 이유가 중요하다
 * 
 * 리프노드의 합만을 구해야 하는데, 중간 노드들의 합도 구하게 된다!!
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
    if (idx == input_n) return;

    if (isPrimeNum(sum)) cnt++;

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