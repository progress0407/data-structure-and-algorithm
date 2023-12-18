#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string in_str;
    vector<char> v;

    cin >> in_str;

    for(auto e: in_str) v.push_back(e);

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
