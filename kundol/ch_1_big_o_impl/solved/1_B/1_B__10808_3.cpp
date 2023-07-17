#include<bits/stdc++.h>

using namespace std;

/**
 * 알파벳 개수
 *
 * 맵으로 풀기
 */

string input;

map<int, int> mp;
int main() {

    cin >> input;

    for (int i = 0; i < 26; i++) {
        mp[i] = 0;
    }

    for (int e: input) {
        int idx = e-'a';
        mp[idx]++;
    }

    for(auto e: mp) cout << e.second << ' ';

    return 0;
}
