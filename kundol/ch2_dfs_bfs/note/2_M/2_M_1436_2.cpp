#include <bits/stdc++.h>

using namespace std;

/**
 * 영화감독 숌
 * 
 * 잠깐 큰돌님 풀이 보고 기가맥히고 코가 막혀서 다시 품
*/

int input;
int i=666;
int cnt;
string n_str;

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> input;

    while(cnt < input) {
        n_str = to_string(i++);
        if(n_str.find("666") != string::npos) // 찾은 경우
            cnt++;
    }

    cout << n_str << "\n";

    return 0;
}
