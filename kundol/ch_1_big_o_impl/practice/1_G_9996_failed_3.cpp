#include <bits/stdc++.h>
#include <regex>

using namespace std;

/**
 * 한국이 그리울 땐 서버에 접속하지
 */

int N;
string pattern;
vector<string> words;

int main() {

    cin >> N
        >> pattern;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    int pos = pattern.find("*");
    string pre = pattern.substr(0, pos);
    string suf = pattern.substr(pos + 1);

    for (auto word: words) {
        string ch_f = word.substr(0, pre.size());
        string ch_b = word.substr(word.size() - suf.size());

        if (pre == ch_f && suf == ch_b) cout << "DA\n";
        else cout << "NE\n";
    }
    
    return 0;
}
