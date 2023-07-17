#include <bits/stdc++.h>

using namespace std;

/**
 * ROT13
 */

string input;

int main()
{
    getline(cin, input);

    for (int i = 0; i < input.size(); i++)
    {
        int ch = input[i];
        if (ch >= 'a' || ch <= 'z')
        {
            if (ch + 13 > 'z')
                input[i] = (ch + 13) - 26;
            else
                input[i] = (ch + 13);
        }
        else if (ch >= 'A' || ch <= 'Z')
        {
            if (ch + 13 > 'Z')
                input[i] = (ch + 13) - 26;
            else 
                input[i] = (ch + 13);
        }
    }

    cout << input;

    return 0;
}
