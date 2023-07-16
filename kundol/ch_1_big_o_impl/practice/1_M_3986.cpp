    #include <bits/stdc++.h>

    using namespace std;

    /**
     * 좋은 단어
     */

    int N;

    int result;

    int main() {

        cin >> N;

        for (int i = 0; i < N; i++) {
            string str;
            cin >> str;
            stack<char> stk;
            for(char a: str) {
                if(stk.size() && a == stk.top())
                    stk.pop();
                else
                    stk.push(a);
            }
            if(stk.empty())
                result++;
        }

        cout << result;

        return 0;
    }
