#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/**
 * 곱셈
 */

ll A, B, C;

ll bi_op(ll exp) {

    if (exp == 1) return A % C;

    ll val = bi_op(exp / 2);

    if (exp % 2 == 0)
        return (val * val) % C;
    else
        return (((val * val) % C) * A) % C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A
        >> B
        >> C;

    cout << bi_op(B);

    return 0;
}
