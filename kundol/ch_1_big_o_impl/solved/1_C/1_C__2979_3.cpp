#include<bits/stdc++.h>

using namespace std;

/**
 * 트럭 주차
 *
 * 큰돌님 풀이
 * 맵으로 하지 않고 코드에 녹여 놓음,
 * 분기에 따라서 여기서 즉석으로 요금 처리
 */

int A, B, C;
int cnt[100];
int temp;

int main() {

    cin >> A >> B >> C;

    for (int i = 0; i < 3; i++) {
        int st, ed;
        cin >> st >> ed;
        for (int j = st; j < ed; j++) {
            cnt[j]++;
        }
    }

    int tot_price = 0;
    for (int i = 0; i < 100; i++) {
        if (cnt[i]) {
            if (cnt[i] == 1) {
                tot_price += A;
            } else if (cnt[i] == 2) {
                tot_price += 2 * B;
            } else if (cnt[i] == 3) {
                tot_price += 3 * C;
            }
        }
    }

    cout << tot_price;

    return 0;
}
