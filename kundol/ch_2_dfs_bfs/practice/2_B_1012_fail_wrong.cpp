#include<bits/stdc++.h>

using namespace std;

/**
 * 유기농 배추
 *
 * 초기화가 안돼는 문제...
 */

int tc;
int m; // 가로
int n; // 세로
int k; // 배추의 위치 갯수
int x, y;
int mapp[54][54];
int vis[54][54];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void print(const char *message);

void dfs(int y, int x) {

    vis[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (mapp[ny][nx] == 0) continue;
        if (vis[ny][nx] == 1) continue;

        dfs(ny, nx);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> tc;

    for (int i = 0; i < tc; i++) {

        // input
        cin >> n >> m >> k;
        for (int j = 0; j < k; j++) {
            scanf("%d %d", &x, &y);
            mapp[y][x] = 1;
        }
//        print("after input : ");

        // calc
        int result = 0;

        for (int yy = 0; yy < n; yy++) {
            for (int xx = 0; xx < m; xx++) {

                if (mapp[yy][xx] == 0) continue;
                if (vis[yy][xx] == 1) continue;

                result++;
                dfs(yy, xx);
            }
        }

        cout << result << '\n';

        // clear, after each
        for (int yy = 0; yy < 54; yy++) {
            for (int xx = 0; xx < 54; xx++) {
                mapp[yy][xx] = 0;
                vis[yy][xx] = 0;
            }
        }
//        print("after clear : ");
    }

    return 0;
}

/*
void print(const char *message) {
    cout << message << '\n';
    for (int yy = 0; yy < n; yy++) {
        for (int xx = 0; xx < m; xx++) {
            cout << mapp[yy][xx] << ' ';
        }
        cout << '\n';
    }
}
*/

/*
void print(const char *message) {
    cout << message << '\n';
    for (int yy = 0; yy < 20; yy++) {
        for (int xx = 0; xx < 20; xx++) {
            cout << mapp[yy][xx] << ' ';
        }
        cout << '\n';
    }
}
*/
