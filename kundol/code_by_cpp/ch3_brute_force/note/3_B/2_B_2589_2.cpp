#include<bits/stdc++.h>

using namespace std;

int in_l; // 세로
int in_w; // 가로

char mp[54][54];
int wei[54][54];

int max_dist_one_loop = -1;
int max_dist = -1;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int y,x;

/**
 * 보물섬
 * 
 * L 육지 1
 * W 바다 0
*/

int bfs(int iy, int ix) {

    queue<pair<int, int>> q;
    memset(wei, 0, sizeof(wei));
    int mx = -1;

    wei[iy][ix] = 1;
    q.emplace(iy, ix);

    while(q.size()) {
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= in_l || nx < 0 || nx >= in_w) continue;
            if(mp[ny][nx] == 'L' && wei[ny][nx] == 0 ) {
                wei[ny][nx] = wei[y][x] + 1;
                mx = max(wei[ny][nx], mx);
                q.emplace(ny, nx);
            }
        }
    }

    return mx - 1;
}

int main() {

    cin >> in_l >> in_w;

    for (int y = 0; y < in_l; y++) {
        for (int x = 0; x < in_w; x++) {
            cin >> mp[y][x];
        }
    }

    for (int y = 0; y < in_l; y++) {
        for (int x = 0; x < in_w; x++) {
            if(mp[y][x] == 'W') continue;
            max_dist_one_loop = bfs(y, x);
            max_dist = max(max_dist_one_loop, max_dist);
        }
    }

    cout << max_dist << "\n";

    return 0;
}
