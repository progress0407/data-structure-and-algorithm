#include<bits/stdc++.h>

using namespace std;

const int n = 3;

int m[n][n];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int visited[n][n];

void go(int y, int x) {

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (m[ny][nx] == 0 || visited[ny][nx]) continue;

        visited[ny][nx] = 1;
        cout << ny << " :: " << nx << '\n';
        go(ny, nx);
    }


}


int main() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    visited[0][0] = 1;
    cout << 0 << " :: " << 0 << '\n';
    go(0, 0);

}
