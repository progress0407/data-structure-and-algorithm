#include<bits/stdc++.h>

using namespace std;

/**
 * 유기농 배추
 *
 */

int tc;

int m; // 가로 x
int n; // 세로 y
int k; // 배추 개수
int y, x;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int mapp[54][54];
bool vis[54][54];

void dfs(int y, int x) {
    vis[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (mapp[ny][nx] == 1 && !vis[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;

    while (tc-- > 0) {
        // 초기화
        fill(&mapp[0][0], &mapp[0][0] + 54 * 54, 0);
        fill(&vis[0][0], &vis[0][0] + 54 * 54, 0);

        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            mapp[y][x] = 1;
        }

        int res = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (mapp[y][x] == 1 && !vis[y][x]) {
                    res++;
                    dfs(y, x);
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}
