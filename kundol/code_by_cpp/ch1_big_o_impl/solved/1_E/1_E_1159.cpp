#include <bits/stdc++.h>
using namespace std;

int N;
int alp[26]; // 0:a ~ 25:z
int mx;

int main()
{

    cin >> N;

    vector<char> names;
    string name;
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        char ch = name[0];
        alp[ch]++;
    }

    for (int e : alp)
    {
        if (e > mx) mx = e;
    }

    if(mx >= 5) cout << alp[mx];
    else cout << "PREDAJA" ;

    return 0;
}
