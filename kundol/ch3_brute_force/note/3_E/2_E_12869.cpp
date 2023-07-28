#include<bits/stdc++.h>

using namespace std;

/**
 * 뮤탈리스크
*/

vector<int> v;

int n_input;

int attacks[6][3] = {
    {9,3,1},
    {9,1,3},
    {3,9,1},
    {3,1,9},
    {1,9,3},
    {1,3,9}
};

struct ScvHp {
    int a;
    int b;
    int c;
};

int dist[61][61][61];
int mn_dist = 1e6;

bool check(ScvHp& scvHp) {
    if(scvHp.a <= 0 && scvHp.b <= 0 && scvHp.c <= 0)
        return true;

    return false;
}

void bfs(ScvHp scvHp) {

    queue<ScvHp> q;

    dist[scvHp.a][scvHp.b][scvHp.c] = 0;
    q.push(scvHp);

    while(q.size()) {

        ScvHp target = q.front(); q.pop();

        // cout<< target.a << ":" << target.b << ":" << target.c << "\n";

        if(check(target)) {
            int currurnt_dist = dist[target.a][target.b][target.c];
            mn_dist = min(currurnt_dist, mn_dist);

            // cout << "currurnt_dist: " << currurnt_dist << "\n";
            // cout << "target: " << target.a << ":" << target.b << ":" << target.c << "\n";

            continue;
        }

        for(auto attack : attacks) {

            int _a = max(0, target.a - attack[0]);
            int _b = max(0, target.b - attack[1]);
            int _c = max(0, target.c - attack[2]);

            q.push({_a, _b, _c});
            dist[_a][_b][_c] = dist[target.a][target.b][target.c] + 1;
        }
    }
}

int main() {

    cin >> n_input;

    int scv[3] = {0,0,0};

    for (int i = 0; i < n_input; i++)
        cin >> scv[i];

    bfs({scv[0], scv[1], scv[2]});

    cout << mn_dist;

    return 0;
}