#include<bits/stdc++.h>

using namespace std;

/**
 * 연속된 3개의 문자
 *
 */


/**
 * 방법 1
 */
/*bool hasThreeConsecutive(const std::string& str) {
    int count = 1;  // 현재 문자가 이미 하나 있으므로 카운트를 1로 시작
    for (size_t i = 1; i < str.size(); ++i) {
        if (str[i] == str[i - 1]) {
            ++count;
            if (count == 3) return true;  // 연속된 세 개의 동일 문자를 찾음
        } else {
            count = 1;  // 다른 문자를 찾았으므로 카운트를 초기화
        }
    }
    return false;  // 연속된 세 개의 동일 문자를 찾지 못함
}*/

/**
 * 방법 2
 */
bool hasThreeConsecutive(string str) {
    int c_n = 3; // 연속된 숫자

    for (int i = 0; i < str.size() - (c_n - 1); i++) {
        if ((str[i] == str[i + 1]) && (str[i + 1] == str[i + 2]))
            return true;
    }

    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << hasThreeConsecutive("aaa") << "\n";
    cout << hasThreeConsecutive("bbba") << "\n";
    cout << hasThreeConsecutive("bba") << "\n";
    cout << hasThreeConsecutive("abbab") << "\n";


    return 0;
}
