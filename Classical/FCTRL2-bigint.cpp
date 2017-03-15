#include<bits/stdc++.h>

using namespace std;

// add two big integers in the form of vectors of short type.
// given vectors a and b addition operation will be performed and results will be stored in vector res.
// the order a and b does not mater.
// complexity O(n) (where n the size of result)
void bigIntAdd(vector<short>& a, vector<short>& b, vector<short>& res){
	
		if(a.size() < b.size())
			swap(a,b);
		
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

void bigIntMul(vector<short>& a,vector<short>& b, vector<short>& res){
		
	}

int main(){
		vector<short> a,b,res;
		a.push_back(1);
		a.push_back(2);
		a.push_back(9);
		a.push_back(1);
		a.push_back(2);
		a.push_back(9);
		b.push_back(2);
		b.push_back(3);
		b.push_back(1);
		b.push_back(2);
		b.push_back(9);
		
		bigIntAdd(b,a,res);
		for(int i=0;i<res.size();i++){
			cout<<res[i];
			}
		cout<<endl;
		
	}
