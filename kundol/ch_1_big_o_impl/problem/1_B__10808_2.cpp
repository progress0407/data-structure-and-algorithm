#include<bits/stdc++.h>

using namespace std;

/**
 * 알파벳 개수
 */

string input;
int arr[26];

int main() {

    cin >> input;

    // Cast from pointer to smaller type 'int' loses information
    for (int e: input) {
        int idx = (int) e - (int) 'a';
        arr[idx] += 1;
    }

    for (int e: arr) cout << e << ' ';

    return 0;
}
