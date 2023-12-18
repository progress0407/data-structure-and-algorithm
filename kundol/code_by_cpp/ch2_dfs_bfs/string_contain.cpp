#include<bits/stdc++.h>

using namespace std;

/**
 * 문자열 포함 여부
 */


bool containsVowel(const string& str) {
    string vowels = "aeiouAEIOU";
    for (char c : str) {
        if (vowels.find(c) != std::string::npos) { // 모음이 있을 경우
            return true;  // 모음을 찾았으므로 true를 반환
        }
    }
    return false;  // 모음을 찾지 못했으므로 false를 반환
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << containsVowel("apple") << "\n";
    cout << containsVowel("bcd") << "\n";
    cout << containsVowel("bcad") << "\n";
    cout << containsVowel("aaee") << "\n";


    return 0;
}
