#include<bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter) {
	
	vector<string> list;
	int pos = 0;
	
    while((pos = input.find(delimiter)) != string::npos) {
    	string word = input.substr(0, pos);
		list.push_back(word);
    	input.erase(0, pos + delimiter.size());
	}
	
	list.push_back(input);
    
    return list;
}

int main(){
	
	string str = "ab cd ef", d = " ";
	vector<string> res = split(str, d);
	for(string s: res) {
		cout << s << '\n';
	}
}
