/*********************************************************************
 * Name: super reduced strings
 * Source: hackerank
 * Algo: using stack
 * time complexity: O(N)
 * space complexity: O(N)
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


void super_reduced_string(string s){
	
	vector<char> ans;
	rep(i,s.length()){
		if(i ==0 || s[i]!=ans.back()){
			ans.pb(s[i]);
		}
		else
			ans.pop_back();
		
	}
	
	if(ans.size() == 0)
		cout<<"Empty String"<<endl;
	else{
		rep(i,ans.size())
			cout<<ans[i];
		cout<<endl;
	}
	
    
}

int main() {
    string s;
    cin >> s;
    super_reduced_string(s);
    return 0;
}
