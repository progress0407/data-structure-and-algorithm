#include<bits/stdc++.h>

using namespace std;

int n, m;

int arr[104][104];
int vis[104][104];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void go(int y, int x) {

    for (int i = 0; i < n; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
        if (arr[ny][nx] == 0 || vis[ny][nx]) continue;

        vis[ny][nx] = 1;
        cout << "visit ! :: " << ny << " : " << nx << "\n";

        go(ny, nx);
    }
}


int main() {

    cin >> n >> m;

    int res = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> arr[y][x];
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (arr[y][x] == 0 || vis[y][x]) continue;

            vis[y][x] = 1; res++;
            cout << "new island ! :: " << y << " : " << x << "\n";
            go(y, x);
        }
    }

    cout << "result: " << res << "\n";
}
