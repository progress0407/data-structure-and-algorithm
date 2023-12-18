#include<bits/stdc++.h>

using namespace std;

#define y1 aaaa

/**
 * 영역 구하기
 */

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int n, m, k;
int x1, y1, x2, y2;
int cnt;
vector<int> s_list;


int ma[104][104];
int vis[104][104];

int dfs(int y, int x) {

    int s = 1;
    vis[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if (ma[ny][nx] == 0 && !vis[ny][nx]) {
            s += dfs(ny, nx);
        }
    }

    return s;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;

    // draw map
    for (int i = 0; i < k; ++i) {

        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                ma[y][x] = 1;
            }
        }
    }

    for (int y = 0; y < m; ++y) {
        for (int x = 0; x < n; ++x) {
            if (ma[y][x] == 0 && !vis[y][x]) {
                int s = dfs(y, x);
                cnt++;
                s_list.push_back(s);
            }
        }
    }

    sort(s_list.begin(), s_list.end());

    cout << cnt << '\n';
    for (int e: s_list) cout << e << ' ';


    return 0;
}
