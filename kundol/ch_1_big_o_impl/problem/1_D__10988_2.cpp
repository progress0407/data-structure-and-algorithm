#include<bits/stdc++.h>

using namespace std;

/**
 * 팰린드롬인지 확인하기
 *
 * 큰돌님 풀이에 가깝게 풀기
 */

string input;
string rev;

int main() {

    cin >> input;
    rev = input;
    reverse(rev.begin(), rev.end());

    if (input == rev) cout << 1;
    else cout << 0;

    return 0;
}
