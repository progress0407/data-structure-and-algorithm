#include<bits/stdc++.h>

using namespace std;

/**
 * 일곱 난장이
 * 큰돌님 풀이
 * 조합 9 C 7 == 9 C 2 임을 착안
 *
 * 1. 전체 합을 구한다
 * 2. r=2인 조합을 만들어서 그 둘의 합을 구한다
 * 3. 전체합 - 둘의 합 == 100인 걸 찾고, 전체 인원에서 그 둘을 제거한다 => 답
 *
 * vector 특정 원소 제거를 value로
 */

int n = 9;
vector<int> v;

int main() {


    for (int i = 1; i <= n; i++) {
        int in;
        cin >> in;
        v.push_back(in);
    }

    int allSum = 0;
    for (int e: v) allSum += e;

    vector<int> ex;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            int subSum = v[i] + v[j];
            if (allSum - subSum == 100) {
                ex.push_back(v[i]);
                ex.push_back(v[j]);
            }
        }
    }

    for (int val: ex) {
        v.erase(remove(v.begin(), v.end(), val),
                v.end());
    }

    sort(v.begin(), v.end());

    for (int e: v) cout << e << "\n";

    return 0;
}


