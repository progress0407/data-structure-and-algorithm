#include<bits/stdc++.h>

using namespace std;

/**
 * 팰린드롬인지 확인하기
 *
 * 문자열 바꾸기
 * 우영우는 거꾸로 해도 우영우다
 */

string input;
string rev;
int isThat() {

    rev = input;
    reverse(rev.begin(), rev.end());

    if (input == rev) {
        return 1;
    }

    return 0;
}

int main() {

    cin >> input;

    cout << isThat();

    return 0;
}
