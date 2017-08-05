#include<iostream>

using namespace std;
int main(){

	int t;
	cin>>t;
	while(t--){
		
		int a,b,op=1;
		cin>>a>>b;
		if(a==0)
			cout<<0;
		else if(b==0)
			cout<<1;
		else {
			while(b!=0){
				if((b%2)!=0){
					op = (op * a) % 10;
					b-=1;
				} else{
					a= (a * a) % 10;
					b = b/2;
				}
			}
			cout<<op;
		}
		cout<<endl;
		
	}
}
