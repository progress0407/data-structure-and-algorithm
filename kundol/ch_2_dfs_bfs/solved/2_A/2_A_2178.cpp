#include<bits/stdc++.h>

using namespace std;

/**
 * 미로 탐색
 */

int n, m, x, y;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int mapp[104][104];
int vis[104][104];

void bfs(int init_y, int init_x) {

    queue<pair<int, int>> q;
    q.push({init_y, init_x});
    vis[init_y][init_x] = 1;

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {

            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (mapp[ny][nx] == 0) continue;
            if (vis[ny][nx] >= 1) continue;

            vis[ny][nx] = vis[y][x] + 1;
            q.push({ny, nx});
        }
    }

}

int main() {

    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%1d", &mapp[y][x]);
        }
    }

    bfs(0, 0);

    cout << vis[n - 1][m - 1] << '\n';

    return 0;
}
