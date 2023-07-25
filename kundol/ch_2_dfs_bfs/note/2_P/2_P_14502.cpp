#include <bits/stdc++.h>

using namespace std;

/**
 * 연구소
 * 
 * 다시 풀었을때 33분 소요
 * dfs 뼈대 코드 실수 약 10분정도 소모
*/

int in_n, in_m;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int mp[10][10];
int t_mp[10][10]; // copy용
vector<pair<int, int>> virusese;
vector<pair<int, int>> walls;

void dfs(int y, int x) {

    t_mp[y][x] =  2; // 방문처리한것이나 마찬가지

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || ny>= in_n || nx<0 || nx>=in_m) continue;
        if(t_mp[ny][nx] == 0) 
            dfs(ny,nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> in_n >> in_m;

    for (int y = 0; y < in_n; y++) {
        for (int x = 0; x < in_m; x++) {
            cin >> mp[y][x];

            int dot = mp[y][x];

            if(dot == 0) walls.push_back({y,x});
            else if(dot == 2) virusese.push_back({y,x});
        }
    }

    int wallsSize = walls.size();
    int cnt_mx = -1;
    int cnt = 0;
    for(int i=0; i < wallsSize; i++) {

        for (int j = i+1; j < wallsSize; j++) {
            
            for (int k = j+1; k < wallsSize; k++) {
                // init
                cnt = 0;
                for (int y = 0; y < in_n; y++)  for (int x = 0; x < in_m; x++) t_mp[y][x] = mp[y][x];

                // set walls
                t_mp[walls[i].first][walls[i].second] = 1;
                t_mp[walls[j].first][walls[j].second] = 1;
                t_mp[walls[k].first][walls[k].second] = 1;

                // set viruses
                for(auto v: virusese) dfs(v.first, v.second);

                // count safe zones
                for (int y = 0; y < in_n; y++)  for (int x = 0; x < in_m; x++) 
                    if(t_mp[y][x] == 0) cnt++;

                cnt_mx = max(cnt, cnt_mx);
            }
        }
    }

    cout<< cnt_mx<<'\n';

    return 0;
}
