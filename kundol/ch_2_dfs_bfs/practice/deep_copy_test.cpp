#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[2][2] = {
            {0, 0},
            {0, 1}
    };

    int b[2][2];
    b = a;
    a[1][1] = 10;


    return 0;
}
