#include<bits/stdc++.h>

using namespace std;

/**
 * 알파벳 개수
 */

string input;
int a[26];

int main() {

    cin >>input;

    for(auto s: input) {
        int i = s - 97;
        a[i] ++;
    }

    for(int e: a) cout << e << " ";

    return 0;
}
