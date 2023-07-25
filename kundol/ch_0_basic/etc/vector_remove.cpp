#include <bits/stdc++.h>

using namespace std;

template <typename T>
void remove_value(vector<T>& vec, T value) {
    vec.erase(remove(vec.begin(), vec.end(), value), vec.end());
}

template <typename T>
void remove_at_index(vector<T>& vec, int idx) {
    if(idx < vec.size()) { // Always good to do a bounds check
        vec.erase(vec.begin() + idx);
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 3, 4, 5, 3};

    // #1
    // remove_value(nums, 3); // nums: {1, 2, 4, 5}

    // #2
    int index_to_remove = 2; // for example, we want to remove the element at index 2
    remove_at_index(nums, index_to_remove);
    
    for(int& n : nums) cout << n << " ";

    return 0;
}
