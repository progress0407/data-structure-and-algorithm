#include<bits/stdc++.h>
using namespace std;


vector<string> split(string str, string delimiter) {

	vector<string> words;
	string::size_type pos ;
	while((pos = str.find(delimiter)) != string::npos) {

		string word = str.substr(0, pos);
		words.push_back(word);
		str.erase(0, pos + delimiter.size());
	}

	words.push_back(str);

	return words;
}

int main(){
	
    auto res = split("ab cd ef", " ");

	for(auto s: res)  cout << s << ' ';
}

