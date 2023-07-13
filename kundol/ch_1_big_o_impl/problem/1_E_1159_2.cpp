#include <bits/stdc++.h>
using namespace std;

int N;
int cnt['z' - 'a' + 1];

int main()
{

    cin >> N;

    for (char i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        cnt[name[0] - 'a']++;
    }

    vector<char> v;
    for (int i = 0; i < cnt.size(); i++)
    {
        int word_cnt = cnt[i];
        if (word_cnt >= 5)
        {
            v.push_back(i + 'a');
        }
    }

    sort(v.begin(), v.end());
    if (v.empty())
    {
        for (auto e : v)
            cout << e;
    }
    else
    {
        cout << "PREDAJA";
    }

    return 0;
}
