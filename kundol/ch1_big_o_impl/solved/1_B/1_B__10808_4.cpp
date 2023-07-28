#include<bits/stdc++.h>

using namespace std;

/**
 * 알파벳 개수
 *
 * 큰돌님 풀이로 풀기
 */

string input;
int cnt[26];

int main() {

    cin >> input;

    for (int c: input) cnt[c - 'a']++;

    for (int e: cnt) cout << e << ' ';

    return 0;
}
