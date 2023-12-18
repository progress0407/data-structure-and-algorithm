#include <bits/stdc++.h>

using namespace std;

/**
 * 영화감독 숌
*/

int i=666;
int n;
int cnt;
string n_cnt[10004];
string n_str;

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    do {
        
        n_str = to_string(i++);

        // check
        for (int j = 0; j < (int) n_str.size() - 2; j++) {
            char a = n_str[j];
            char b = n_str[j+1];
            char c = n_str[j+2];

            if(a == '6' && a == b && b == c) {
                n_cnt[++cnt] = n_str;
                break;
            }
        }
    } while(n_cnt[n] == "");

    cout << n_cnt[n] << "\n";

    return 0;
}
