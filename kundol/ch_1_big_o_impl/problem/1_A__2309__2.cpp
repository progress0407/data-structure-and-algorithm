#include<bits/stdc++.h>

using namespace std;

/**
 * 일곱 난장이
 * 큰돌님 풀이 참고
 * 순열
 *
 * 1. 정렬
 * 2. 순열로 나열하면서 7개 합이 100인걸 찾는다, 여기서 loop 벗어남
 * 3. 결과 출력
 */

int n = 9;
int a[9 + 1];

int main() {

    for (int i = 1; i <= 9; i++) cin >> a[i];
    sort(a + 1, a + 10);

    do {
        int sum = 0;
        for (int i = 1; i <= 7; i++) sum += a[i];
        if (sum == 100) {
            break;
        }
    } while (next_permutation(&a[1], &a[1] + 9));

    for (int i = 1; i <= 7; i++) cout << a[i] << "\n";

    return 0;
}


