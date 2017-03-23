#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int ng,nm,gMax =0 ,mMax= 0;
		cin>>ng>>nm;
		for(int i=0;i<ng;i++){
			int temp;
			cin>>temp;
			if(temp > gMax)
				gMax = temp;
		}
		for(int i=0;i<nm;i++){
			int temp;
			cin>>temp;
			if(temp>mMax)
				mMax = temp;
		}
		if(mMax>gMax)
			cout<<"MechaGodzilla"<<endl;
		else if(mMax<gMax)
			cout<<"Godzilla"<<endl;
		else 
			cout<<"Godzilla"<<endl;
		
	}
	return 0;
}
