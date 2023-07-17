#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/**
 * 곱셈
 *
 * A^B % C= A*...*A %C
 *
 * 짝수
 * val = A^(B/2) % C라고 하면
 * val * val
 *
 * 홀수
 * val * val * A % C
 */

ll A, B, C;

ll bi_op(ll exp) {

    if (exp == 0) return 1;
    else if (exp == 1) return A;

    ll val = bi_op(exp / 2) % C;

    if (exp % 2 == 0) return (val * val) % C;
    else return (val * val * (A % C)) % C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A
        >> B
        >> C;

    cout << bi_op(B) % C << "\n";

    return 0;
}
