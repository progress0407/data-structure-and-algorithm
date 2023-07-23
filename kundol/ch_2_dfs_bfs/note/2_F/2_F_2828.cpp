#include<bits/stdc++.h>

using namespace std;

/**
 * 사과 담기 게임
 *
 */

int n; // 맵 크기
int m; // 바구니 크기
int b_lp = 0; // 바구니의 left position
int b_rp; // 바구니의 right position
int d_m; // 움직임 변위; 앞으로 움직일 곳 (방향 포함)
int m_cnt; // 움직인 총 횟수
int jj; // 사과 개수
int p; // 사과 1개 위치 (1 <= p <= n)


void moveBasketPosition(int leftPosition) {
    b_lp += leftPosition;
    b_rp = b_lp + m - 1;
}

bool canPut() {
    return (b_lp <= p && p <= b_rp);
}

int judgeMove() {
    if (p < b_lp) return p - b_lp;
    else if (p > b_rp) return p - b_rp;
    else {
        cout << "Wrong Wrote Algorithm\n";
        exit(0);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> jj;
    moveBasketPosition(1);

    for (int i = 0; i < jj; i++) {
        cin >> p;
        if (!canPut()) {
            d_m = judgeMove();
            moveBasketPosition(d_m);
            m_cnt += abs(d_m);
        }
    }

    cout << m_cnt << '\n';

    return 0;
}
