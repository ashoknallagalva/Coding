/*********************************************************************
 * Name: Camel Case
 * Source: hackerank
 * Algo: using ASCII comparision
 * time complexity: O(N)
 * space complexity: O(1)
 * Author: Ashok Nallagalva
 * *******************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll  long long int
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define mp make_pair
#define mod 1000000007
#define s second
#define pb push_back

int main(){

	string s;
	int words=0;
	cin>>s;
	
	rep(i,s.length()){
		if(s[i]>='A' && s[i] <= 'Z')
			words++;
	}
	cout<<words+1<<endl;
	return 0;
	
}
