#include<bits/stdc++.h>
using namespace std;

vector<int> v;

void fn1();
void fn2();

int main() {
//    fn1();
    fn2();

    return 0;
}

void fn1() {

//    for (int i = 1; i <= 5; ++i) {
//        v.push_back(i);
//        v.push_back(i);
//    }

    for (int i: v) cout << i << " ";
    cout << '\n';

    auto it = unique(v.begin(), v.end());
    cout << "it: " << it - v.begin() << "\n";

    for (int e: v) cout << e << " ";
}

void fn2() {

    v= {2,2,1,1,3,3,4,4,5,5};

    sort(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()), v.end());

    for (int e: v) cout << e << " ";
}

