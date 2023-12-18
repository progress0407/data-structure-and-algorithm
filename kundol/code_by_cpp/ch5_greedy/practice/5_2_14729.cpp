#include <bits/stdc++.h>

using namespace std;

/**
 * 칠무해
 * 
 * PQ 이해
*/

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    priority_queue<float, vector<float>, greater<float>> pq;

    for (int i = 0; i < n; i++) {
        float input;
        cin >> input;
        pq.push(input);
    }


    for (int i = 0; i < 7; i++) {
        float top = pq.top(); pq.pop();
        printf("%.3f\n", top);
    }
    
    

    return 0;
}

