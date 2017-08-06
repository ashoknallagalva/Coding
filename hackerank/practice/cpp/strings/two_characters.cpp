/*********************************************************************
 * Name: Two Characters 
 * Source: hackerank
 * Algo: BF
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
#define pr(v) cout<<v<<endl;
#define f first
#define mp make_pair
#define mod 1000000007
#define s second
#define pb push_back


int isValid(string s){
	
	if(s.empty())
		return 0;
	rep(i,s.length()-1){
		if(s[i]==s[i+1])
			return -1;
	}
	return s.length();
}

void resetVector(vector<bool> &a){
	
	rep(i,a.size())
		a[i] = false;
}

string uniqueChars(string s){
	vector<bool> map(26);
	resetVector(map);
	string res;
	
	rep(i,s.length()){
		map[s[i]-'a'] = true;
	}
	rep(i,26){
		if(map[i])
			res.pb('a'+i);
	}
	
	return res;
}


int main(){

	
	
	int n, maximum=0;;
	string s,unqChars;
	cin>>n>>s;
	unqChars = uniqueChars(s);
	
	rep(i,unqChars.length()-1){
		for(int j=i+1;j < unqChars.length(); j++){

			string ans;
			char p=unqChars[i],q=unqChars[j];
			rep(k,s.length()){
				if(s[k]==p || s[k]==q)
					ans.pb(s[k]);
			}
			maximum = max(maximum,isValid(ans));
			
		}

	}
	
	cout<<maximum<<endl;
	
	return 0;
	
}
