#include<bits/stdc++.h>

using namespace std;

void printVector(vector<short>& a){
		for(int i=0;i<a.size();i++){
			cout<<a[i];
			}
		cout<<endl;
	}

// add two big integers in the form of vectors of short type.
// given vectors a and b addition operation will be performed and results will be stored in vector res.
// the order a and b does not mater.
// complexity O(n) (where n the size of result)
void bigIntAdd(vector<short>& x, vector<short>& y, vector<short>& res){
	
		vector<short> &a = x.size()<y.size()?y:x;
		vector<short> &b = x.size()<y.size()?x:y;
		
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
		for(;aIndex>=0;aIndex--)
			res.push_back(a[aIndex]);
		reverse(res.begin(),res.end());
	}

void bigIntMul(vector<short>& x,vector<short>& y, vector<short>& res){
	
		vector<short> &a = x.size()<y.size()?y:x;
		vector<short> &b = x.size()<y.size()?x:y;
		
		vector<short> interSum,temp;
		for(int bIndex = b.size()-1; bIndex >=0; bIndex--){
			int carry = 0;
			vector<short> mulVector,temp;
			
			//place value adjestment
			for(int i = ((b.size()-1)-bIndex); i>0;i--)
				mulVector.push_back(0);
				
			for(int aIndex = a.size()-1;aIndex>=0;aIndex--){
					int mulValue;
					mulValue = (a[aIndex] * b[bIndex]) + carry;
					carry = mulValue/10;
					mulVector.push_back(mulValue % 10);					
				}
			if(carry!=0)
				mulVector.push_back(carry);
			reverse(mulVector.begin(),mulVector.end());
			bigIntAdd(mulVector,interSum,temp);
			interSum = temp;			
			}
		
		for(int i=0;i<interSum.size();i++)
			res.push_back(interSum[i]);
		
	}
	
void convertIntToVectorShort(int a,vector<short>& res){
		while(a){
				res.push_back(a%10);
				a=a/10;
			}
		reverse(res.begin(),res.end());
	}

int main(){		
	
		vector<vector<short> > ansTabel;
		vector<short> initial;
		initial.push_back(1);
		ansTabel.push_back(initial);
		for(int i=1;i<=100;i++){
				vector<short> res;
				vector<short> a;
				convertIntToVectorShort(i,a);
				bigIntMul(a,ansTabel[i-1],res);
				ansTabel.push_back(res);				
			}
		
		int t;
		cin>>t;
		while(t--){
				int n;
				cin>>n;
				printVector(ansTabel[n]);			
		}
		
		return 0;
	}
