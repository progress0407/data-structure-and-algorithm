#include<bits/stdc++.h>
using namespace std;

map<int, int> m;

int main(){
	
	vector<int> v {1,1, 2,2, 3,3};
	
	for(auto e : v) cout<< e << ' ';
	
	for(int i=0; i<5; i++) {
		auto e = v[i];
		if(m[e]) {
			m[e]++;
		} else {
			m[e]=1;
		}
	}
	
	vector<int> res;
	
	for(auto e : m) {
		res.push_back(e.first);
	}
	
	cout<< "\nresult\n";
	for(auto e : res) cout<< e << ' ';
	
	return 0;
}

