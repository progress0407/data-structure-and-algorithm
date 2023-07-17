#include <bits/stdc++.h>

using namespace std;

/**
 * 곱셈
 */

int A, B, C;

int main() {

    cin >> A
        >> B
        >> C;

    long long mul = 1;
    for(int i=0; i< B; i++) mul *= A;

    cout << mul % C;

    return 0;
}
