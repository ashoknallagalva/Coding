#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<stack>

using namespace std;

int main(){

	int n;
	cin>>n;
	while(n!=0){
		vector<int> asorted;
		stack<int> s;
		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			if(s.empty()){
				s.push(temp);
			} else if(s.top()>temp){
				s.push(temp);
			} else if(s.top() < temp){
				while(!s.empty() && s.top()< temp){
					asorted.push_back(s.top());
					s.pop();
				}
				s.push(temp);
			} else{
				s.push(temp);
			}
			
		}
		while(!s.empty()){
			asorted.push_back(s.top());
			s.pop();
		}
		
		if(is_sorted(asorted.begin(),asorted.end()))
			cout<<"yes"<<endl;
		else 
			cout<<"no"<<endl;
		
		cin>>n;
	}
	return 0;

}
