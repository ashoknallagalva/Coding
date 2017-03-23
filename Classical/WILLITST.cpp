#include<iostream>

using namespace std;

int main(){
	long long n,n1;
	cin>>n;
	n1=n-1;
	
	if(n <=0)
		cout<<"TAK";
	else if(n>1 && (n & n1) == 0)
		cout<<"TAK";
	else
		cout<<"NIE";
	cout<<endl;
	
}
