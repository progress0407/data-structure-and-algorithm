#include<bits/stdc++.h>

using namespace std;

/**
 * 인접한 행렬 방문하기
 */

int arr[10][10] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

bool vis[10];

int delts[4][2] = {
        {0,  1},
        {0,  -1},
        {1,  0},
        {-1, 0}
};

void dfs(int x, int y) {

    for (auto delt: delts) {

        int dx = delt[0];
        int dy = delt[1];

        if (x + dx < 0 || x + dx >= 10 || y + dy < 0 || y + dy >= 10)
            continue;
        cout << "arr: " << arr[x + dx][y + dy] << "\n";
        cout << "vis: " <<  vis[x + dx] << "\n";
        if (arr[x + dx][y + dy] && !vis[x + dx]) {
            vis[x + dx] = true;
            cout << "visit: " << x + dx << "\n";
            dfs(x + dx, y + dy);
        }
    }
}

int main() {

    // input
    vis[0] = true;
    dfs(0, 1);

    return 0;
}