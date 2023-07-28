#include<bits/stdc++.h>

using namespace std;

// 구현문제를 대하는 태도

int main() {
    string dopa = "umzunsic";

//    Q1. 앞에서부터 3개의 문자열을 출력하라
    string str1 = dopa.substr(0, 3);
    cout << str1 << "\n";

//    Q2. 해당 문자열을 거꾸로 해서 출력하라.
    reverse(dopa.begin(), dopa.end());
    cout << dopa << "\n";

//    Q3. 해당 문자열 끝에 "umzunsik"이란 문자열을 추가하라.
    dopa = "umzunsic";
    cout << dopa << " umzunsik";


    return 0;
}