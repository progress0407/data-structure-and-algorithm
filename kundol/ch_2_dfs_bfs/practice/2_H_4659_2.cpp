#include<bits/stdc++.h>

using namespace std;

string str;

bool isA(string str) {
    string vowels = "aeiouAEIOU";
    for (auto &c: str)
        if (vowels.find(c) != string::npos)
            return true;

    return false;
}

bool isB(string str) {
    cout << "str: " << str << "\n";
    cout << "str size: " << str.size() << "\n";
    int strSize = (int) str.size();
    for (int i = 0; i < strSize - 2; i++) {
        char c = str[i];
        cout << "current index: " << i << "current char : " << c << "\n";
        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
            if ((str[i] == str[i + 1]) && (str[i + 1] == str[i + 2]))
                return true;
    }
    return false;
}

string s;

int main() {

    while (true) {
        cin >> str;
        if (str == "end") break;
//        int ret = isA(str);
        int ret = isB(str);
        cout << "result: " << ret << "\n";
    }

    return 0;
}
