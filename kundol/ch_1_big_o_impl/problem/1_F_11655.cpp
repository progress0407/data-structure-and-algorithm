#include <bits/stdc++.h>

using namespace std;

/**
 * ROT13
 */

string input;
string decoded;

int main() {
    getline(cin, input);
    // input = "Baekjoon Online Judge";

    for (char ch: input) {
        if (ch >= 'a' && ch <= 'z') {
            int de_ch = ch + 13;
            if (de_ch > 'z') {
                decoded += (de_ch - 26);
            } else {
                decoded += (de_ch);
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            int de_ch = ch + 13;
            if (de_ch > 'Z') {
                decoded += (de_ch - 26);
            } else {
                decoded += (de_ch);
            }
        } else {
            decoded += ch;
        }
    }

    input.

    cout << decoded;

    return 0;
}
