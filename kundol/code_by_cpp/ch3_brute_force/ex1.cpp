#include <bits/stdc++.h>

using namespace std;

/**
 * made by 큰돌] 랄로의수
 * 
 * n번째 2400 찾기
*/

int n;

int main() {
    
    cin >> n;

    for(int i=2400;;i++) {
        string str = to_string(i);

        if(str.find("2400") != string::npos) {
            n--;
            if(n == 0) {
                cout << str << '\n';
                return 0;
            }
        }
    }

    return 0;
}