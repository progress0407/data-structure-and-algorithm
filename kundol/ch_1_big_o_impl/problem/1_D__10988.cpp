#include<bits/stdc++.h>

using namespace std;

/**
 * 팰린드롬인지 확인하기
 */

string input;

int isThat() {
    int totalSize = input.size();
    int end = totalSize - 1;
    int mid = totalSize / 2;

    for (int i = 0; i < mid; i++) {
        int r = end - i;
        if (input[i] != input[r]) {
            return 0;
        }
    }

    return 1;
}

int main() {

    cin >> input;

    cout << isThat();

    return 0;
}
