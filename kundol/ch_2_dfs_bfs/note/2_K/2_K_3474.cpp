#include <bits/stdc++.h>

using namespace std;

int t; // test case
int n; // number
int ret;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    for(int i=0; i< t; i++) {
        cin >> n;
        
        for (int j = 5; j <= n; j*=5)
        {
            ret += (n/j);
        }
        
        cout << ret << '\n';
        ret=0;
    }

    return 0;
}
