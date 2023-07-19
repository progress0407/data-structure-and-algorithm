#include<bits/stdc++.h>

using namespace std;

const int max_n = 104;

// n: 세로, m : 가로
int n, m, st_x, st_y, ed_x, ed_y;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int mapp[max_n][max_n];

int dist[max_n][max_n];

void bfs(int init_y, int init_x) {
    queue<pair<int, int>> q;
    q.emplace(init_y, init_x);
    dist[init_y][init_x] = 1;

    while (q.size()) {
        pair<int, int> p = q.front(); q.pop();
        int y = p.first;
        int x = p.second;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 예외처리
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(dist[ny][nx]) continue;
            if(mapp[ny][nx] == 0) continue;

            q.emplace(ny, nx);
            dist[ny][nx] = dist[y][x] + 1;
        }
    }
}

int main() {
    // given
    scanf("%d %d", &n, &m);
    cin >> st_y >> st_x;
    cin >> ed_y >> ed_x;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapp[i][j];
        }
    }

    cout << "\n\n";

    bfs(st_y, st_x);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << dist[ed_y][ed_x] << '\n';

    return 0;
}
