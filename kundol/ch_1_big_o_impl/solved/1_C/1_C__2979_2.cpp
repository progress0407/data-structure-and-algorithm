#include<bits/stdc++.h>

using namespace std;

/**
 * 트럭 주차
 *
 * 1. 요금 맵 만들기: 트럭대수: 요금
 * 2. 시간에 따른 트럭 갯수 배열 만들기::  idx: 시간, val: 트럭 대수
 * 3. 시간 맵 만들기:: 각 트럭대수 : 시간
 * 4. 합계 구하기 (행렬곱):: 요금 맵 * 시간 맵
 */
int a, b, c;
vector<pair<int, int>> st_ed_list;
int t[104];

map<int, int> p_mp; // 트럭수: 요금
map<int, int> t_mp; // 트럭수: 시간
int main() {

    cin >> a >> b >> c;
    p_mp[1] = a;
    p_mp[2] = 2 * b;
    p_mp[3] = 3 * c;

    for (int i = 0; i < 3; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        st_ed_list.push_back(p);
    }

    // time 배열 만들기
    for (auto e: st_ed_list) {
        int st = e.first;
        int ed = e.second;

        for (int i = st; i < ed; i++) {
            t[i]++;
        }
    }

    // 시간 맵으로 바꾸기, t->t_mp
    for (int i = 0; i < 104; i++) {
        if (t[i] == 0) continue;

        t_mp[t[i]]++;
    }

    // 총 요금
    int tot_price = 0;
    for (int i = 1; i <= 3; i++) {
        tot_price += p_mp[i] * t_mp[i];
    }

    cout << tot_price;

    return 0;
}
