#include<bits/stdc++.h>
using namespace std;

void exit_fn() {

    cout << "sub routine: start\n";
//    exit(0);
    return 0;
    cout << "sub routine: end\n";
}

int main(){

    cout << "main: start\n";

    exit_fn();

    cout << "b: end\n";

    return 0;
}


