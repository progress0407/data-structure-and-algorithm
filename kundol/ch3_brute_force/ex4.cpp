#include <bits/stdc++.h>

using namespace std;

/**
 * 긍정왕 홍철이의 구걸 여행
*/

int mp[3][3] = {
    {10, 20, 21}, 
    {70, 90, 12},
    {80, 110, 120} 
};

int vis[3][3];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int sum, vector<int> nums) {

    sum += mp[y][x];
    nums.push_back(mp[y][x]);

    if(y==2 && x==2) {
        cout << "nums: " << " ";
        for(auto& n : nums) cout << n << " ";
        cout << "\n";

        cout << "sum: " << sum << "\n\n";
        return;
    }

    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || ny >= 3 || nx<0 || nx >= 3) continue;

        if(!vis[ny][nx]) {
            vis[ny][nx] = 1;
            dfs(ny, nx, sum, nums);
            vis[ny][nx] = 0;
        }
    }
}

int main() {

    vector<int> nums;
    dfs(0, 0, 0, nums);
    
    return 0;
}