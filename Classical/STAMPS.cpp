#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int scNo=1;scNo<=t;scNo++){
		int sum,fs;
		vector<int> brws;
		cin>>sum>>fs;
		for(int i=0;i<fs;i++){	
			int temp;
			cin>>temp;
			brws.push_back(temp);
		}
		sort(brws.begin(),brws.end());
		for(int i= fs-1,count=1; i>=0; i--,count++){
				sum = sum - brws[i];
				if(sum<=0){
					cout<<"Scenario #"<<scNo<<":"<<endl;
					cout<<count<<endl<<endl;
					break;
				}
		}
		
		if(sum>0){
			cout<<"Scenario #"<<scNo<<":"<<endl;
			cout<<"impossible"<<endl<<endl;
		}
			
	}
}
