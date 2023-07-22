#include<bits/stdc++.h>

using namespace std;

/**
 * 비밀번호 발음하기
 *
 * 1. 모음을 포함
 * 2. 모음 3개 or 자음 3개 연속
 * 3. 같은 글자 연속 2번 오면 안된다
 *  - ee || oo 는 허용한다
 */

string vowels = "aeiouAEIOU";
string str;

bool isVowel(char &ch) {

    return vowels.find(ch) != string::npos;
}

bool isA(string str) {

    for (auto &c: str)
        if (isVowel(c))
            return true;

    return false;
}

bool isB(string &str) {

    int strSize = str.size();
    for (int i = 0; i < strSize - 2; i++) {
        char a = str[i];
        char b = str[i + 1];
        char c = str[i + 2];
        if (isalpha(a)) {
            if ((isVowel(a) && isVowel(b) && isVowel(c)) // 연속 3개 모음
            || (!isVowel(a) && !isVowel(b) && !isVowel(c)))  // 연속 3개 자음
                return false;
        }
    }

    return true;
}

bool isC(string &str) {

    int strSize = str.size();

    for (int i = 0; i < strSize - 1; i++) {
        if (str[i] == str[i + 1]) {
            char c = str[i];
            if (c == 'e' || c == 'o')
                continue;
            else
                return false;
        }
    }

    return true;
}

string s;

int main() {

    while (true) {
        cin >> str;

        if (str == "end") break;

        int a = isA(str);
        int b = isB(str);
        int c = isC(str);

//        cout << "a: " << a << "\n";
//        cout << "b: " << b << "\n";
//        cout << "c: " << c << "\n";

        if (a && b && c) {
            cout << "<" << str << "> is acceptable.\n";
        } else {
            cout << "<" << str << "> is not acceptable.\n";
        }
    }

    return 0;
}
