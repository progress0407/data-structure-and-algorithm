#include<bits/stdc++.h>

using namespace std;

/**
 * 빈도 정렬
 *
 * (Java에서 풀이 떠올림) compare 이용
 */

int n; // 메시지 길이
int c; // 숫자의 최대 크기
int tmp;
int order_cnt = 1;

struct Record {
    int num;
    int cnt;
    int order;
};

vector<Record> table;

bool isExistThenAdd() {
    for (auto &r: table) {
        if (r.num == tmp) {
            r.cnt++;
            return true;
        }
    }
}

bool compare(const Record &a, const Record &b) {
    if (a.cnt != b.cnt) {
        return a.cnt > b.cnt;
    } else {
        return a.order < b.order;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (!isExistThenAdd()) {
            Record r = {tmp, 1, order_cnt};
            table.push_back(r);
        }
        order_cnt++;
    }

    sort(table.begin(), table.end(), compare);

    for (auto& r: table) {
        for (int i = 0; i < r.cnt; i++) cout << r.num << ' ';
    }
    cout << '\n';

    return 0;
}
