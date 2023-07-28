#include<bits/stdc++.h>

using namespace std;

/**
 * 안전 영역
 *
 * 안전한 영역의 Connected Component 문제 풀기
 *
 *
 *
 */

//constexpr auto int_mx = numeric_limits<int>::max();
//constexpr auto int_mn = numeric_limits<int>::min();

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int mn, mx;
int n, ccn, ccn_mx;
int h;
int h_mx = -1;
int h_mn = 104;

int ma[104][104];
int vis[104][104];

// ch: 현재 강물 높이
void dfs(int y, int x, int ch) {

    vis[y][x] = 1;

    for (int i = 0; i < 4; i++) {

        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        if (ma[ny][nx] > ch && !vis[ny][nx]) {
            dfs(ny, nx, ch);
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> h;
            ma[y][x] = h;
            h_mx = max(h, h_mx);
            h_mn = min(h, h_mn);
        }
    }

/*
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << ma[y][x] << ' ';
        }
        cout << '\n';
    }
*/

//    cout << "h_mn: " << h_mn << '\n';
//    cout << "h_mx: " << h_mx << '\n';

    for (int h = h_mn; h <= h_mx; h++) {

        ccn = 1;
        fill(&vis[0][0], &vis[0][0] + 104 * 104, 0);

        cout << "Current Water Height : " << h << '\n';

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                // 땅의 위치가 현재 수심보다 높아야 하고, 방문하지 않은 곳
                if (ma[y][x] > h && !vis[y][x]) {
                    ccn++;
                    dfs(y, x, h);
                    cout << "dfs start: " << y << " : " << x << '\n';
                }
            }
        }
        ccn_mx = max(ccn, ccn_mx);
        cout << ccn << '\n';
    }

    return 0;
}
