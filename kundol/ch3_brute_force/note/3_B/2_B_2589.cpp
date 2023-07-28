#include<bits/stdc++.h>

using namespace std;

int l, w;

/**
 * 보물섬
 * 
 * L 육지 1
 * W 바다 0
*/

int mp[54][54];
int mark[54][54];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int curreunt_one_wei;
int one_wei_mx;
int y, x;

int bfs(int init_y, int init_x) {

    queue<pair<int,int>> q;
	
    mark[init_y][init_x] = 1;
	q.push({init_y, init_x});
    curreunt_one_wei = 1;
	
	while(q.size()) {
		tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= l || nx < 0 || nx >= w) continue;
            if (mp[ny][nx] == 1 && mark[ny][nx] == 0) {
                q.push({ny, nx});
                mark[ny][nx] = mark[y][x] + 1;
                curreunt_one_wei = max(mark[ny][nx], curreunt_one_wei);
            }
        }
	}

    return curreunt_one_wei;
}

int main() {

    cin >> l >> w;

    for (int y = 0; y < l; y++) {
        for (int x = 0; x < w; x++) {
            char dot;
            cin >> dot;
            if(dot == 'L') mp[y][x] = 1;
            else if(dot == 'W') mp[y][x] = 0;
        }
    }

    for (int y = 0; y < l; y++) {
        for (int x = 0; x < w; x++) {

            memset(mark, 0, sizeof(mark));

            if(mp[y][x] == 1) {
                curreunt_one_wei = bfs(y, x);
                one_wei_mx = max(curreunt_one_wei, one_wei_mx);
                // cout << curreunt_one_wei << "\n";
            }
        }
    }

    cout << one_wei_mx - 1 << "\n";

    return 0;
}
