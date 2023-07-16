#include <bits/stdc++.h>

using namespace std;

/**
 * 좋은 단어
 */

int N;

stack<char> st;

int result;

int main() {

    cin >> N;
    // 스택에 값 추가(push)
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(char e : str) {
            if(!st.empty()) {
                char top = st.top();
                if (e == top) {
                    st.pop();
                }
            } else {
                st.push(e);
            }
        }

        // 좋은 단어
        if(st.empty()) {
            result++;
        }

        // clear
        while(!st.empty()) {
            st.pop();
        }
    }

    cout << result;

    return 0;
}
