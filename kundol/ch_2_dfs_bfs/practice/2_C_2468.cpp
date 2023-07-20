#include<bits/stdc++.h>

using namespace std;

/**
 * 안전 영역
 *
 * 안전한 영역의 Connected Component 문제 풀기
 *
 * 1. DFS 알고리즘 작성
 *
 * 2. 여러 가지 테스트 케이스가 있다고 가정 -> fill로 배열들 초기화 하기
 *
 * 3. 최저 높이에서 최고 높이에서 색칠하기 (안전영역/ 안전하지 않은 영역) Connected Component 구하기
 *
 * 4. 가장 최대의 Connected Component 구하기
 */

int n, h, h_max = -1, h_min = 104;
int ccn, ccn_max = -1;
int mapp[104][104];
int water[104][104];
int vis[104][104];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int dfs(int y, int x) {

    vis[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        // 물에 안잠기고 아직 방문하지 않았으면
        if (!water[ny][nx] && !vis[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            cin >> h;
            mapp[y][x] = h;
            h_max = max(h, h_max);
            h_min = min(h, h_min);
        }
    }

//    cout << "min: " << h_min << '\n';
//    cout << "max: " << h_max << '\n';

    for (int h = h_min; h <= h_max; h++) {

        // clear
        ccn = 0;
        fill(&water[0][0], &water[0][0] + 104 * 104, 0);
        fill(&vis[0][0], &vis[0][0] + 104 * 104, 0);

        // 물에 잠기게 하기
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                if (mapp[y][x] <= h) {
                    water[y][x] = 1;
                }
            }
        }

        // ccn 구하기
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {

                // 물에 잠기지 않았고 아직 방문하지 않았다면
                if (!water[y][x] && !vis[y][x]) {
                    dfs(y, x);
                    ccn++;
                }
            }
        }
        ccn_max = max(ccn, ccn_max);
    }

    cout << ccn_max << '\n';

    return 0;
}
