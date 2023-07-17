#include <bits/stdc++.h>

using namespace std;

/**
 * 1
 */

int main() {

    int n;

    while (scanf("%d", &n) != EOF) {

        int cnt = 0;
        long long ones_num = 0;

        while (true) {
            ones_num = ones_num * 10 + 1;
            cnt++;
            if (ones_num % n == 0) {
                cout << cnt << '\n';
                break;
            }
            ones_num %= n;
        }
    }

    return 0;
}
