#include <bits/stdc++.h>

using namespace std;

/**
 * 균형잡힌 세상
*/

string str;

vector<string> split(string str, string delim) {
    int p;
    vector<string> ws;

    while((p = str.find(delim)) != string::npos) {
        string w = str.substr(0, p);
        ws.push_back(w);
        str.erase(0, p+delim.size());
    }
    ws.push_back(str);

    return ws;
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    // cin >> str;
    string str = "So when I die (the [first] I will see in (heaven) is a score list).\n[ first in ] ( first out ).\nHalf Moon tonight (At least it is better than no Moon at all].\nA rope may form )( a trail in a maze.\nHelp( I[m being held prisoner in a fortune cookie factory)].\n([ (([( [ ] ) ( ) (( ))] )) ]).\n .\n.";
    vector<string> ws = split(str, ".\n");
    for (size_t i = 0; i < ws.size(); i++)
    {
        cout << i+1 << ": " << ws[i] <<"\n";
    }
    

    return 0;
}
