#include <bits/stdc++.h>

using namespace std;

/**
 * 팰린드롬 만들기
 * 
 * 시간 초과
*/


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string in_str;
    vector<char> v;
    map<char, int> m;

    cin >> in_str;

    for(auto e: in_str) {
        v.push_back(e);
        m[e]++;
    }

    // 전체가 짝수이면서, 홀수개인 단어가 있다면 펠린드롬이 될 수 없음
        if(v.size() % 2 == 0) {
            for(auto e: m) {
                if(e.second % 2 == 1) {
                    cout << "I'm Sorry Hansoo";
                    exit(0);
                }
            }
        }

    vector<string> fels;
    do {
        string str = "";
        for(auto e: v) str += e;
        string rev= str;
        reverse(rev.begin(), rev.end());
        if(str == rev) {
            fels.push_back(rev);
        }
    } while(next_permutation(v.begin(), v.end()));

    if(fels.empty()) {
        cout << "I'm Sorry Hansoo";
    } else {
        sort(fels.begin(), fels.end());
        cout << fels.front();
    }

    return 0;
}
