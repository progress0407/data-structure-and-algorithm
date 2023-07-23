#include <bits/stdc++.h>

using namespace std;

/**
 * 균형잡힌 세상
*/

string input;
string str;

string extract(string& str) {
    string ret="";
    for(char& c: str) {
        if(c=='[' || c==']' || c=='(' || c == ')') {
            ret+=c;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    while(true) {
        getline(cin, input);

        if(input == ".") break;

        str = extract(input);

        stack<char> stk;

        for(char& c: str) {
            if(stk.empty()) 
                stk.push(c);
            else {
                char top = stk.top();
                if((top == '(' && c == ')') || (top == '[' && c == ']'))
                    stk.pop();
                else 
                    stk.push(c);
            }
        }

        if(stk.empty()) cout << "yes\n";
        else cout << "no\n";
    };
    

    return 0;
}
