#include<bits/stdc++.h>

using namespace std;

int n_input; // 맵의 한변 크기
int m_input; // 남길 치킨집

int dot;

pair<int, int> chi_input_list[20];
int chi_input_cnt;
vector<vector<pair<int, int>>> candidate_chi_list;

vector<pair<int, int>> home_input_list;

/**
 * n C r
 * n: chi_input_cnt
 * r: m_input
*/

void combi(int st, vector<pair<int,int>> v) {
    
    if(v.size() == m_input) {
        candidate_chi_list.push_back(v);
        return;
    }

    for(int i= st + 1 ; i < chi_input_cnt; i++) {
        pair<int,int> chi = chi_input_list[i];
        v.push_back(chi);
        combi(i, v);
        v.pop_back();
    }
}

int main() {

    cin >> n_input >> m_input;

    for (size_t y = 0; y < n_input; y++)
        for (size_t x = 0; x < n_input; x++) {
            cin >> dot;
            if(dot == 2) {
                chi_input_list[chi_input_cnt] = {y, x};
                chi_input_cnt++;
            } else if (dot == 1)
                home_input_list.push_back({y, x});
        }

    // cout<<"chi_input_cnt: "<< chi_input_cnt << "\n";
    // for (int i = 0; i < chi_input_cnt; i++) {
        // auto p = chi_input_list[i];
        // cout << p.first << ":" << p.second << " ";
    // }

    combi(-1, {});

    // for(auto e1 : candidate_chi_list) {
        // for(auto e2: e1) {
            // cout << e2.first <<":"<< e2.second << " ";
        // }
        // cout << "\n";
    // }

    int mn = 1e6;
    for(auto one_chi_list: candidate_chi_list) { 
        int dis_sum = 0;
        for(auto& home: home_input_list) {
            int home_dis = 1e6;
            for(auto& chi: one_chi_list) {
                // calc
                int dis_temp = abs(home.first - chi.first) + abs(home.second - chi.second);
                // cout << "dis: " <<  dis_temp << "\n";
                home_dis = min(dis_temp, home_dis);
            }
            dis_sum += home_dis;
        }
        mn = min(dis_sum, mn);
    }

    cout << mn;

    return 0;
}