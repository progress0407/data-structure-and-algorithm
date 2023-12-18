#include <bits/stdc++.h>

using namespace std;

int w, h;
char mp[104][104];
int ret[104][104];

int main() {

    cin >> h >> w;

    fill(&ret[0][0], &ret[0][0] + 104*104, -1);

    for(int y=0; y< h; y++) {
        for(int x=0; x< w; x++) {
            cin >> mp[y][x];
        }
    }

    for(int y=0; y< h; y++) {

        for(int x=0; x < w; x++) {

            if(mp[y][x] == 'c') {
                ret[y][x] = 0;
                int cnt = 1;
                while(x + 1 < w && mp[y][x + 1] == '.') {
                    ret[y][x+1] = cnt++;
                    x++;
                }
            }
        }
    }

    for(int y=0; y< h; y++) {
        for(int x=0; x< w; x++) {
            cout << ret[y][x] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
