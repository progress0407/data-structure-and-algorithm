#include<bits/stdc++.h>

using namespace std;

/**
 * 불!
*/

int r_in, c_in;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int y,x;

char mp[1004][1004];

int man_vis[1004][1004];
int fire_vis[10][1004][1004]; // z y x
int final_fire_vis[1004][1004];

void man_bfs(int iy, int ix) {

    queue<pair<int, int>> q;

    man_vis[iy][ix] = 1;
    q.emplace(iy, ix);

    while(q.size()) {
        tie(y,x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= r_in || nx < 0 || nx >= c_in) continue;
            char np = mp[ny][nx];
            if(np == 'F' || np == '#' || man_vis[ny][nx]) continue;

            man_vis[ny][nx] = man_vis[y][x] + 1;
            q.emplace(ny, nx);
        }
    }
}

void fire_bfs(int z, int iy, int ix) {

    queue<pair<int, int>> q;

    fire_vis[z][iy][ix] = 1;
    q.emplace(iy, ix);

    while(q.size()) {
        tie(y,x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= r_in || nx < 0 || nx >= c_in) continue;
            char np = mp[ny][nx];
            if(np == '#' || fire_vis[z][ny][nx]) continue;

            fire_vis[z][ny][nx] = fire_vis[z][y][x] + 1;
            q.emplace(ny, nx);
        }
    }
}

int main() {

    cin >> r_in >> c_in;

    pair<int, int> man;
    vector<pair<int, int>> fires;

    for (int y = 0; y < r_in; y++)
        for (int x = 0; x < c_in; x++) {
            char ch;
            cin >> ch;

            mp[y][x] = ch;

            if(ch == 'J') 
                man = {y, x};
            else if (ch == 'F') 
                fires.push_back({y, x});
        }

    man_bfs(man.first, man.second);

    for (int i = 0; i < (int) fires.size(); i++) {
        auto fire = fires[i];
        fire_bfs(i, fire.first, fire.second);
    }
    
    for (int y = 0; y < r_in; y++) {
        for (int x = 0; x < c_in; x++) {
            int mn = 1004;
            for (int i = 0; i < (int) fires.size(); i++) {
                int val = fire_vis[i][y][x];
                mn = min(val, mn);
            }
            final_fire_vis[y][x] = mn;
        }
    }

    // cout << "-----------";
    // for (int y = 0; y < r_in; y++) {
    //     for (int x = 0; x < c_in; x++) {
    //         cout << man_vis[y][x];
    //     }
    //     cout << "\n";
    // }

    // cout << "-----------";
    // for (int y = 0; y < r_in; y++) {
    //     for (int x = 0; x < c_in; x++) {
    //         cout << final_fire_vis[y][x];
    //     }
    //     cout << "\n";
    // }


    if(fires.empty()) {
        int mn = 1004;
        for (int y = 0; y < r_in; y++) {
            for (int x = 0; x < c_in; x++) {
                if(y == 0 || y == r_in -1 || x == 0 || x == c_in) {
                    if(man_vis[y][x] > 0) {
                        int val = man_vis[y][x];
                        mn = min(val, mn);
                    }
                }
            }
        }
        cout << mn << "\n";
    } else {
        int mn = 1004;
        for (int y = 0; y < r_in; y++) {
            for (int x = 0; x < c_in; x++) {
                if(y == 0 || y == r_in -1 || x == 0 || x == c_in) {
                    if(man_vis[y][x] > 0) {
                        if(man_vis[y][x] < final_fire_vis[y][x]) {
                            int val = man_vis[y][x];
                            mn = min(val, mn);
                        }
                    }
                }
            }
        }
        cout << mn << "\n";
    }

    return 0;
}
