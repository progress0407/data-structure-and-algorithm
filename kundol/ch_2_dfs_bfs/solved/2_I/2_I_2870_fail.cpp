#include <bits/stdc++.h>

using namespace std;

int n;
string str;
bool prevDigit = false;
string digit_str = "";
vector<int> nums;

int main() {

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> str;

        int strSize = str.size();
        digit_str = "";
        prevDigit = false;

        for(int j=0; j< (int) strSize; j++) {
            char c = str[j];
            if(!prevDigit && isalpha(c)) { // init or 영 -> 영
                prevDigit = false;
            }
            else if (isdigit(c) && j == strSize - 1)  {// ? -> 숫 -> (마지막)
                digit_str += c;
                nums.push_back(stoi(digit_str));
            }
            else if(!prevDigit && isdigit(c)) { // 영 -> 숫
                digit_str += c;
                prevDigit = true;
            }
            else if(prevDigit && isalpha(c)) { // 숫 -> 영 
                nums.push_back(stoi(digit_str));
                digit_str = "";
                prevDigit= false;
            }
            else if (prevDigit && isdigit(c)) { // 숫 -> 숫
                digit_str += c;
                prevDigit= true;
            }
        }

    }

    sort(nums.begin(), nums.end());
    
    for(auto& n: nums) cout << n << '\n';
    

    return 0;
}
