#include<bits/stdc++.h>

using namespace std;

/**
 * 트리 압축
 *
 * 틀렸다고 하는데.. 도대체 어디서 틀린건지를 모르겠다
 */

int n, x, y;
int mp[64][64];
int vis[64][64];

bool isPureCase(bool isOne, int size, int st_y, int st_x) {
    for (int y = st_y; y < st_y + size; ++y) {
        for (int x = st_x; x < st_x + size; ++x) {
            if (isOne) { // 1 이어야 하는 경우
                if (mp[y][x] != 1) return false;
            } else { // 0 이어야 하는 경우
                if (mp[y][x] != 0) return false;
            }
        }
    }
    return true;
}

string quard(int size, int st_y, int st_x) {

    bool isOne = (mp[st_y][st_x] == 1);

    if (size == 1) return isOne ? "1" : "0";

    if (isPureCase(isOne, size, st_y, st_x))
        return isOne ? "1" : "0";

    int newSize = size / 2;

    return "(" +
           quard(newSize, st_y, st_x) +
           quard(newSize, st_y, st_x + newSize) +
           quard(newSize, st_y + newSize, st_x) +
           quard(newSize, st_y + newSize, st_x + newSize) +
           ")";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            scanf("%1d", &mp[y][x]);
        }
    }

    cout << quard(n, 0, 0);

    return 0;
}
