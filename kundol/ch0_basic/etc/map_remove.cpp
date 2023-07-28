#include <bits/stdc++.h>

using namespace std;

int main() {

    map<int, vector<string>> m;

    // Add some elements to the map.
    m[1] = {"one", "two"};
    m[2] = {"three"};

    int key_to_remove = 1;  // For example, we want to remove the key 2.

    // Removes the key-value pair with the key 2 from the map.
    m.erase(key_to_remove);

    for(auto& e: m)  {
        cout << e.first << ":: ";
        for(auto& ee: e.second) 
            cout << ee << " ";
    }
    

    return 0;
}
