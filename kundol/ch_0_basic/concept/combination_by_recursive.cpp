#include<bits/stdc++.h>
using namespace std;

int n=5, k=3, a[5] = {1,2,3,4,5};

void print(vector<int> b) {
	for(int i : b) cout<< i << " ";
	cout << '\n';
}

void combi(int start, vector<int> v) {
	
	if(v.size() == k) {
		print(v);
		return;
	}
	
	for(int i= start + 1; i < n; i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	
	return;
}


int main(){
	
	vector<int> v;
	combi(-1, v);

	return 0;
}

