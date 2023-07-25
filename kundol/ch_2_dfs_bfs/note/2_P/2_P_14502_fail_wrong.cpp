#include <bits/stdc++.h>

using namespace std;

/**
 * 연구소
*/

int n; // 세로
int m; // 가로
int x,y;

int mp[10][10];
int tmp_mp[10][10]; // 순회용 맵
int vis[10][10];

vector<pair<int, int>> empties;
vector<vector<pair<int, int>>> emptiesList; // 3개씩 뽑힌 후보

vector<pair<int, int>> viruses;


int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void combi(int st, vector<pair<int, int>> v) {

    if(v.size() == 3) {
        emptiesList.push_back(v);
        return;
    }

    for(int i= st+1; i < empties.size() ; i++) {
        v.push_back(empties[i]);
        combi(st, v);
        v.pop_back();
    }
}

void dfs(int y, int x) {

    vis[y][x] = 1;
    tmp_mp[y][x] = 2;
    
    for(int i=0 ; i< 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
        if(tmp_mp[ny][nx] == 0 && !vis[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> mp[y][x];
            if(mp[y][x] == 0) 
                empties.push_back({y, x});
            if(mp[y][x] == 2)
                viruses.push_back({y, x});
        }
    }

    vector<pair<int, int>> temp_v;
    combi(-1, temp_v);

    // cout << "emptiesList size: " << emptiesList.size() << "\n"; // 4.2만개

    int cnt_mx = -1;
    for(auto& ets: emptiesList) {

        int cnt = 0;
        fill(&tmp_mp[0][0], &tmp_mp[0][0] + 10*10, -1);
        fill(&vis[0][0], &vis[0][0] + 10*10, 0);

        // deep copy
        for (int y = 0; y < n; y++) for (int x = 0; x < m; x++) tmp_mp[y][x] = mp[y][x];

        // set walls
        for(auto& et: ets) {
            int y = et.first;
            int x = et.second;
            tmp_mp[y][x] = 1;
        }

        // 감염
        for(auto& v: viruses) dfs(v.first, v.second);

        for (int y = 0; y < n; y++) for (int x = 0; x < m; x++) 
            if(tmp_mp[y][x] == 0) cnt++;
        cnt_mx = max(cnt, cnt_mx);
    }

    // cout << "cnt_mx: " << cnt_mx << "\n";
    cout << cnt_mx << "\n";

    // for(auto& e: emptiesList) {
        // for(auto& ee: e) {
            // cout << ee.first << ":" << ee.second << " ";
        // }
        // cout << "\n";
    // }    

    return 0;
}
