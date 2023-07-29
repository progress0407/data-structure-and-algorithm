#include<bits/stdc++.h>

using namespace std;

/**
 * 인구 이동
*/

int n_in, l_in, r_in;

int mp[54][54];
int vis[54][54];

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int y, x;

void dfs(int y, int x, set<pair<int, int>>& cords) {

    vis[y][x] = 1;
    cords.emplace(y,x);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n_in || nx < 0 || nx >= n_in || vis[ny][nx]) continue;

        int dif = abs(mp[ny][nx] - mp[y][x]);
        if(dif >= l_in && dif <= r_in)
            dfs(ny, nx, cords);
    }
}

int main() {

    cin >> n_in >> l_in >> r_in;

    for (int y = 0; y < n_in; y++)
        for (int x = 0; x < n_in; x++)
            cin >> mp[y][x];

    int cnt = 0;
    while(true) {

        bool isMove = false;
        memset(vis, 0, sizeof(vis));

        for (int y = 0; y < n_in; y++) {
            for (int x = 0; x < n_in; x++) {

                if(vis[y][x]) continue;

                // init
                set<pair<int, int>> cords;

                dfs(y, x, cords);

                if(cords.size() <= 1) continue;

                // 움직임 판단
                isMove = true;
                int sum = 0;
                for(auto& c : cords) 
                    sum += mp[c.first][c.second];
                
                int avg = sum / cords.size();
                for(auto& c : cords)
                    mp[c.first][c.second] = avg;
            }
        }

        // 움직었는지 아니었는지
        if(!isMove) break;

        cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
