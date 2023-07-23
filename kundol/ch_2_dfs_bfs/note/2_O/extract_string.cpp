#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> extractBrackets(const string& input) {
    vector<char> brackets;
    for (char ch : input) {
        if (ch == '[' || ch == ']' || ch == '(' || ch == ')') {
            brackets.push_back(ch);
        }
    }
    return brackets;
}

string extractBracketsAsString(const string& input) {
    string brackets;
    for (char ch : input) {
        if (ch == '[' || ch == ']' || ch == '(' || ch == ')') {
            brackets.push_back(ch);
        }
    }
    return brackets;
}

int main() {
    string input = "[ first in ] ( first out ).";

    vector<char> brackets = extractBrackets(input);

    cout << "[1] list of char: ";
    for (char ch : brackets) {
        cout << "'" << ch << "', ";
    }
    cout << "\n\n" ;

    string brackets2 = extractBracketsAsString(input);

    // 결과 출력
    cout << "[2] string: " << brackets2 << "\n";

    return 0;
}
