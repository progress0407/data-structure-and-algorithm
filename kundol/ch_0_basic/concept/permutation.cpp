#include<bits/stdc++.h>

using namespace std;

 // 배열
void permutation_1() {
    int a[] = {1, 2, 3};

    do {
        for (int i: a) cout << i << " ";
        cout << '\n';
    } while (next_permutation(&a[0], &a[0] + 3));
}

 // 벡터
void permutation_2() {
    vector<int> a = {1, 2, 3};

    do {
        for (int i: a) cout << i << " ";
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
}

// 정렬이 되지 않았을 경우에 대한 문제
void permutation_3() {
    vector<int> a = {2, 1, 3, 100, 200};
    sort(a.begin(), a.end());
    long long totCnt = 0;

    do {
//		for(int i : a) cout << i << " ";
        for (int i = 0; i < 2; i++) cout << a[i] << " ";
        cout << '\n';
        totCnt += 1;
    } while (next_permutation(a.begin(), a.end()));

    cout << "tot cnt = " << totCnt << '\n';
}


int main() {
    permutation_3();
}



