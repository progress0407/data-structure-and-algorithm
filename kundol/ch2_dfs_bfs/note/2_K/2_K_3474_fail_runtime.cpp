#include <bits/stdc++.h>

using namespace std;

int t; // test case
int n; // number
int ret;
int arr[104];

int weight5(int n) {
    int cnt = 0;
    int r = 0;
    while(n%5==0 && r%5==0 && n >= 5) {
        r = n % 5;
        n /= 5;
        cnt++;
    }
    if (r == 0) {
        return cnt;
    } else {
        return 1;
    }
}

int main() {

    cin >> t;

    for(int i=0; i< t; i++) {
        cin >> n;
        ret = 0;
        for(int j=5; j<= n; j +=5) {
            int r = weight5(j);
            ret += r;
        }
        cout << ret << '\n';
    }

    return 0;
}
