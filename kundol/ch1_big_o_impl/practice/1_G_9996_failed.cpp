#include <bits/stdc++.h>
#include <regex>
using namespace std;

/**
 * 한국이 그리울 땐 서버에 접속하지
 */

int N;
string pattern;
vector<string> words;
char st, ed;

int main() {
    
    cin >> N
        >> pattern;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    st = pattern.front();
    ed = pattern.back();

    for(string word : words) {
        if (st != word.front() || ed != word.back()) {
            cout << "NE\n";
            continue;
        }
        cout << "DA\n";
    }

    return 0;
}
