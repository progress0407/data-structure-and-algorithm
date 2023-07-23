#include <bits/stdc++.h>

using namespace std;

/**
 * 연구소
*/

int n; // 세로
int m; // 가로

int mp[10][10];
vector<pair<int, int>> empties;
vector<vector<pair<int, int>>> emptiesList; // 3개씩 뽑힌 후보

void combi(int st, vector<pair<int, int>> v) {

    if(v.size() == 3) {
        emptiesList.push_back(v);
        return;
    }

    for(int i= st; i < empties.size() ; i++) {
        v.push_back(empties[i]);
        combi(st+1, v);
        v.pop_back();
    }
}

int main() {
    //ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> mp[y][x];
            if(mp[y][x] == 0) 
                empties.push_back({y, x});
        }
    }

    combi(-1, {});

    for(auto& e: emptiesList) {

        for(auto& ee: e) {
            cout << ee.first << ":" << ee.second << " ";
        }
        cout << "\n";
    }    

    return 0;
}
