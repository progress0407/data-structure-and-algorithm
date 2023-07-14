#include<bits/stdc++.h>

using namespace std;

void input_1(int N, vector<int> &nums) {
    nums.resize(N);
    for (auto &num : nums) {
        cin >> num;
    }
}

void input_2(int N, vector<int> &nums) {

    for (int i=0;i<N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
}

int main(){

    int N=3;
    vector<int> nums;
//    input_1(N, nums);
    input_2(N, nums);

    cout << "out:: ";
    for(auto e : nums) cout << e << ' ';

    return 0;
}





