#include <bits/stdc++.h>

using namespace std;

/**
 * 1
 */

int main() {

    int n;
    cin >> n;
    int cnt = 0;

    string one_str = "";
    while (true) {
        one_str += "1";
        cnt++;
        if (stoll(one_str) % n == 0) {
            cout << cnt;
            exit(0);
        }
    }

    return 0;
}
