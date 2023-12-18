#include<bits/stdc++.h>

using namespace std;

map<int, int> mp;
map<string, string> mp2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << mp[1] << '\n';
    cout << mp2["aaa"] << '\n';
    for(auto i : mp) cout << i.first << " : " << i.second;
    cout << '\n';

    for(auto i : mp2) cout << i.first << " : " << i.second;

    return 0;
}
