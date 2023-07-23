#include <bits/stdc++.h>

using namespace std;

/**
 * 괄호
*/

int n;
string ps;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ps;
        stack<char> stk;
        
        for(char& c : ps) {
            if(stk.empty()) {
                stk.push(c);
            } else {
                int last = stk.top();
                
                if(last == '(' && c == ')') stk.pop();    
                else 
                    stk.push(c);
            }
        }

        if(stk.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
    

    return 0;
}
