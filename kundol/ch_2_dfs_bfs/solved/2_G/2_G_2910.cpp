#include<bits/stdc++.h>

using namespace std;

/**
 * 빈도 정렬
 *
 * Struct 이용
 *
 * (Java에서 풀이 떠올림) compare 이용
 */

int n; // 메시지 길이
int c; // 숫자의 최대 크기
int num_in; // 입력받은 숫자
int order = 1; // 입력 순서
map<int, int> mp_cnt;
map<int, int> mp_order;
vector<pair<int, int>> v; // 숫자: 개수

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second > b.second; // 내림 차순
    } else {
        return mp_order[a.first] < mp_order[b.first]; // 오름차순
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;

    for (int i = 0; i < n; ++i) {
        cin >> num_in;
        mp_cnt[num_in]++;
        if (mp_order[num_in] == 0) // Not Exist
            mp_order[num_in] = order;
        order++;
    }

    for (auto &e: mp_cnt)
        v.push_back({e.first, e.second});

    sort(v.begin(), v.end(), cmp);

    for (auto &e: v)
        for (int i = 0; i < e.second; ++i)
            cout << e.first << ' ';

    return 0;
}
