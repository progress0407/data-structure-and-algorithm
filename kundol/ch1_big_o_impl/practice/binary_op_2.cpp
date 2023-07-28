#include <bits/stdc++.h>

using namespace std;

/**
 * 곱셈
 */

typedef long long ll;

ll bi(int exp) {

    if (exp == 0) return 1;
//    else if(exp == 1) return 2;

    ll val = bi(exp / 2);

    if (exp % 2 == 1) return val * val * 2;
    else return val * val;
}

int main() {

    cout << "2^1: " << bi(1);
    cout << "\n2^2: " << bi(2);
    cout << "\n2^3: " << bi(3);
    cout << "\n2^4: " << bi(4);
    cout << "\n2^5: " << bi(5);

    return 0;
}
