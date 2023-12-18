#include <bits/stdc++.h>

using namespace std;

/**
 * 두 수의 합
*/

int n, x, cnt, l, r;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        v.push_back(in);
    }

    cin >> x;

    sort(v.begin(), v.end());

    // cout << "-------------------\n";
    // for(auto e: v) {
    //     cout << e << " ";
    // }
    // cout << "-------------------\n";

    l = 0;
    r = n-1;

    while(l < r) {
        int sum = v[l] + v[r];

        if(sum == x) {
            cnt++;
            // printf("(%d, %d)\n", v[l], v[r]);
            l++;
            r--;
        } 
        else if (sum  > x)
            r--;
        else
            l++;
    }

    cout << cnt << '\n';

    return 0;
}

