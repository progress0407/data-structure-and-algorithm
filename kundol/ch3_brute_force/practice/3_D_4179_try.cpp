#include<bits/stdc++.h>

using namespace std;

/**
 * 불!
*/

int r_in, c_in;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};


int vis[1004][1004];

int y, x;

/**
 * 사람은 한칸 움직인다 -> 4방향 으로 먼저 움직인다 (경우의 수)
 *  - 이에 따라 불들이 모든 방향으로 한칸씩 움직인다 (움직임이 확정돼 있다)
 * 
 * 불들 n은 각자 한칸 움직인다
*/
void dfs(int y, int x, int[] mp) {

    for(int i=0; i<4 ; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0|| ny>=r_in || nx<0 || nx>=c_in) continue;
        int np = mp[ny][nx];
        if(np != '#' && np == 'F' && vis[ny][nx]) {
            mp[y][x] = '#';
            mp[ny][nx] = 'J';

            

            dfs(ny, nx, mp);
        }
    }

    // 불들은 각자 n칸씩 움직인다
}

int main() {

    cin >> r_in >> c_in;

    int mp[r_in][c_in];
    
    pair<int, int> man;
    vector<pair<int, int>> fires;

    for (int y = 0; y < r_in; y++)
        for (int x = 0; x < c_in; x++) {
            char ch;
            cin >> ch;

            if(ch == 'J') 
                man = {y, x};
            else if (ch == 'F') 
                fires.push_back({y, x});
        }


    return 0;
}
