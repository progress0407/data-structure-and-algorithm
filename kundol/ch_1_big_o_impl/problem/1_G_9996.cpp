#include<bits/stdc++.h>

using namespace std;
int n;
string s, ptn, pre, suf, word;

int main() {
    cin >> n;
    cin >> ptn;
    int pos = ptn.find('*');
    string st = ptn.substr(0, pos);
    string ed = ptn.substr(pos + 1);

    for (int i = 0; i < n; i++) {
        cin >> word;

        if (word.size() < st.size() + ed.size()) { // 반례
            cout << "NE\n";
            continue;
        }

        // 메인 로직
        if (st == word.substr(0, st.size()) &&
            ed == word.substr(word.size() - ed.size()))
            cout << "DA\n";
        else
            cout << "NE\n";
    }

    return 0;
}