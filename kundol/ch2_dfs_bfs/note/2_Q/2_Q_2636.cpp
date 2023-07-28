#include <bits/stdc++.h>

using namespace std;

/**
 * 치즈
 * 
 * 안쪽0 : 9 로 마킹
 * 
 * 풀이하는데 50분 초과...
*/

int in_h, in_w;
int decay_time=0;
int ccn=0; // connected component 갯수

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int ny, nx;

int mp[104][104];
int lastMp[104][104];
int vis[104][104];

void printMp() {
    cout << "------print map----\n";
    for (int y = 0; y < in_h; y++) {
        for (int x = 0; x < in_w; x++) 
            cout << mp[y][x] << " ";
        cout << "\n";
    }
}


void dfs_mark_inner_empty(int y, int x) {
    vis[y][x] = 1;

    for (int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny<0 || ny>=in_h || nx<0 || nx>=in_w) continue;
        if(mp[ny][nx] == 0 && !vis[ny][nx]) {
            dfs_mark_inner_empty(ny, nx);
        }
    }
}


void mark_inner_empty() {
    dfs_mark_inner_empty(0, 0);

    // mark
    for (int y = 0; y < in_h; y++) 
        for (int x = 0; x < in_w; x++) 
            if(!(mp[y][x] == 1) && !vis[y][x]) 
                mp[y][x] = 9;
}


void decay_cheese() {
    for (int y = 0; y < in_h; y++) 
        for (int x = 0; x < in_w; x++)
            if(mp[y][x] == 1) {
                for(int i=0; i< 4; i++) {
                    ny = y + dy[i];
                    nx = x + dx[i];

                    if(ny<0 || ny>=in_h || nx<0 || nx>=in_w) continue;
                    if(mp[ny][nx] == 0) 
                        mp[y][x] = 2;
                        // mp[y][x] = 0; // 똑같이 0이라고 하면... 순서 개념이 생겨버려서, 이에따라 안지워야할 치즈를 지울수 있다
                }
            }
    for (int y = 0; y < in_h; y++) 
        for (int x = 0; x < in_w; x++)
            if(mp[y][x] == 2)
                mp[y][x] = 0;
}


bool check_all_empty() {
    for (int y = 0; y < in_h; y++)  for (int x = 0; x < in_w; x++) 
        if(mp[y][x] != 0)
            return false;

    return true;
}


void dfs_connected_component(int y, int x) {
    vis[y][x] = 1;

    for (int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny<0 || ny>=in_h || nx<0 || nx>=in_w) continue;
        if(!vis[ny][nx] && !(lastMp[ny][nx]==1)) {
            dfs_connected_component(ny, nx);
        }
    }
}

void process_connected_component() {
    
    for (int y = 0; y < in_h; y++) for (int x = 0; x < in_w; x++) 
        if(lastMp[y][x] == 1) {
            dfs_connected_component(y, x);
            ccn++;
        }
    cout << decay_time << "\n";
    cout << ccn << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> in_h >> in_w;

    for (int y = 0; y < in_h; y++)
        for (int x = 0; x < in_w; x++)
            cin >> mp[y][x];
    
    while(true) {
        decay_time++;

        // 마지막 배열 복사
        for (int y = 0; y < in_h; y++) for (int x = 0; x < in_w; x++)
            lastMp[y][x] = mp[y][x];

        // 안쪽의 0과 밖의 0 분리
        mark_inner_empty();
        
        // 부식시키기, 이때 밖의 0 개념 필요
        decay_cheese();

        // 안밖 개념 지우기
        for (int y = 0; y < in_h; y++) for (int x = 0; x < in_w; x++)
            if(mp[y][x] == 9) 
                mp[y][x] = 0;

        // 방문자 배열 초기화
        fill(&vis[0][0], &vis[0][0] + 104*104, 0);

        // check All 0
        if(check_all_empty()) {
            process_connected_component();
            break;
        }
    }

    return 0;
}
