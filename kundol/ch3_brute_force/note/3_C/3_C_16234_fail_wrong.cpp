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

set<pair<int, int>> cords;

void dfs(int y, int x) {

    vis[y][x] = true;
    cords.emplace(y,x);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n_in || nx < 0 || nx >= n_in) continue;
        if(vis[ny][nx]) continue;

        int dif = abs(mp[ny][nx] - mp[y][x]);
        if(l_in <= dif  && dif <= r_in)
            dfs(ny, nx);
    }
}


int main() {

    cin >> n_in >> l_in >> r_in;

    for (int y = 0; y < n_in; y++)
        for (int x = 0; x < n_in; x++)
            cin >> mp[y][x];

    int cnt = 0;
    
    while(true) {
        memset(vis, 0, sizeof(vis));
        cords.clear();

        bool isMove = false;
        for (int y = 0; y < n_in; y++) {
            for (int x = 0; x < n_in; x++) {

                cords.clear();

                if(vis[y][x]) continue;

                dfs(y, x);  // 후에 set에 쌓임

                if (cords.size() <= 1) continue;

                // 후처리
                isMove = true;

                int sum = 0;
                int avg = 0;
                for(auto& p : cords) {
                    tie(y, x) = p;
                    sum += mp[y][x]; 
                }
                avg = sum / cords.size();
                // 각 좌표에 avg 
                for(auto& p : cords) {
                    tie(y, x) = p;
                    mp[y][x] = avg;
                }
            }
        }

        if(!isMove) break;

        cnt++;
    }
    
    cout << cnt << "\n";

    return 0;
}
