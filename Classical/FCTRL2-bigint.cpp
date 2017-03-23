#include<bits/stdc++.h>

using namespace std;

typedef vector<short> V_S;

void printVector(V_S &a){for(int i=0;i<a.size();i++)cout<<a[i];cout<<endl;}
void bigIntAdd(V_S& x, V_S& y, V_S& res){	
		V_S &a = x.size()<y.size()?y:x, &b = x.size()<y.size()?x:y;		
		int aSize = a.size(), bSize = b.size(),carry = 0, aIndex = aSize-1;		
		for(int bIndex = bSize-1;bIndex >= 0 ;bIndex--){
				int sum=0,remainder=0;
				sum = a[aIndex] + b[bIndex] + carry;
				carry = sum/10;
				remainder = sum%10;
				res.push_back(remainder);
				aIndex--;				
			}
		res.push_back(a[aIndex]+carry);
		aIndex--;	
		for(;aIndex>=0;aIndex--)res.push_back(a[aIndex]);
		reverse(res.begin(),res.end());
	}

void bigIntMul(V_S& x,V_S& y, V_S& res){	
		V_S &a = x.size()<y.size()?y:x, &b = x.size()<y.size()?x:y;	
		V_S interSum,temp;
		for(int bIndex = b.size()-1; bIndex >=0; bIndex--){
			int carry = 0;
			V_S mulVector,temp;
			for(int i = ((b.size()-1)-bIndex); i>0;i--)mulVector.push_back(0);
				
			for(int aIndex = a.size()-1;aIndex>=0;aIndex--){
					int mulValue;
					mulValue = (a[aIndex] * b[bIndex]) + carry;
					carry = mulValue/10;
					mulVector.push_back(mulValue % 10);					
				}
			if(carry!=0)mulVector.push_back(carry);
			reverse(mulVector.begin(),mulVector.end());
			bigIntAdd(mulVector,interSum,temp);
			interSum = temp;			
			}
		
		for(int i=0;i<interSum.size();i++)res.push_back(interSum[i]);		
	}
	
void convertIntToVectorShort(int a,V_S& res){
		while(a){res.push_back(a%10);a=a/10;}
		reverse(res.begin(),res.end());
	}

int main(){	
		vector<V_S > aT;
		aT.push_back(V_S());
		aT[0].push_back(1);
		for(int i=1;i<=100;i++){
				V_S res;
				V_S a;
				convertIntToVectorShort(i,a);
				bigIntMul(a,aT[i-1],res);
				aT.push_back(res);				
			}
		
		int t;
		cin>>t;
		while(t--){
				int n;
				cin>>n;
				printVector(aT[n]);			
		}
		
		cout<<endl;
		return 0;
	}
