#include<bits/stdc++.h>

using namespace std;

struct Foo {
    int a;
    string b;
};

vector<Foo> foos;

int main() {

    // foos.push_back({1, "aa"});

    // Foo first = foos.front();

    if( foos.empty() ) {
        cout << "empty" << '\n';
    } else {
        cout << "something exist" << '\n';
    }

    // cout << first.a << '\n';

    return 0;
}
