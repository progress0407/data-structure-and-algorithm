#include<bits/stdc++.h>
using namespace std;

int fibo(int n) {
	
	if(n==0) return 0;
	if(n==1 || n==2) return 1;
	
	return fibo(n-1)+fibo(n-2);
}

int main(){
	int res = fibo(6);
	cout << "res: " << fibo(1) << '\n';
	cout << "res: " << fibo(3) << '\n';
	cout << "res: " << fibo(6) << '\n';
}


