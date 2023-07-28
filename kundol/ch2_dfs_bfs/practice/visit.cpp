#include<bits/stdc++.h>

using namespace std;

/**
 * 인접한 행렬 방문하기
 *
 * 1-2, 1-3, 3-4
 */

const int V = 10;
bool arr[V][V], visited[V];

void go(int n) {
    visited[n] = true;
}

int main() {

    arr[1][2] = true;
    arr[2][1] = true;

    arr[1][3] = true;
    arr[3][1] = true;

    arr[3][4] = true;
    arr[4][3] = true;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (visited[i]) continue;

            if (arr[i][j]) {
                visited[i] = true;
                cout << "visit ! : " << i << '\n';
            }
        }
    }
    return 0;
}