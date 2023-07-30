#include <bits/stdc++.h>

using namespace std;

/**
 * 칠무해
 * 
 * PQ 이해
*/

int n;
vector<float> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    priority_queue<float> pq;

    for (int i = 0; i < n; i++) {
        float input;
        cin >> input;
        if(pq.size() >= 7){
            pq.push(input); 
            pq.pop();
        } else 
            pq.push(input);
    }

    while(pq.size()) {
        v.push_back(pq.top());
        pq.pop();
    }

    reverse(v.begin(), v.end());

    for(float& e: v) 
        printf("%.3f\n", e);

    return 0;
}

