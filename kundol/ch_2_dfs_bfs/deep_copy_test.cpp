#include<bits/stdc++.h>

using namespace std;

/**
 * Shallow Copy
 */
void someFunc(string str) {
    str[0] = '_';
}

/**
 * Deep Copy
 */
void someFunc2(string &str) {
    str[0] = '_';
}

int main() {

    string str = "abc";

    someFunc(str);

    cout << "after func call: " << str << "\n";

    someFunc2(str);

    cout << "after func call: " << str << "\n";

    return 0;
}
