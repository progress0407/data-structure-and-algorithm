#include <bits/stdc++.h>
#include <regex>

using namespace std;

/**
 * 한국이 그리울 땐 서버에 접속하지
 */

int N;
string pattern;
vector<string> words;

vector<string> split(string str, string d) {

    vector<string> ws;
    int p;
    while ((p = str.find(d)) != string::npos) {
        string w = str.substr(0, p);
        ws.push_back(w);
        str.erase(0, p + d.size());
    }

    ws.push_back(str);

    return ws;
}

int main() {

    cin >> N
        >> pattern;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    vector<string> chs = split(pattern, "*");
    string f = chs.front();
    string b = chs.back();

    for (auto word: words) {

        string ch_f = word.substr(0, f.size());
        string ch_b = word.substr(word.size() - b.size());

        if(f==ch_f && b==ch_b) cout << "DA\n";
        else cout << "NE\n";
    }

    return 0;
}
