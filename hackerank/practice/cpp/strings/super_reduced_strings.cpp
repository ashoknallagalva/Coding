/*********************************************************************
 * Name: super reduced strings
 * Source: hackerank
 * Algo: solved in navie method
 * time complexity: O(N^3)
 * space complexity: O(1)
 * Author: Ashok Nallagalva
 * *******************************************************************/


#include <iostream>


using namespace std;

bool isNotReducible(string s){

		for(int i=0;i<s.length()-1;i++){
			if(s[i]==s[i+1])
				return true;
		}
		return false;
}

string super_reduced_string(string s){
	bool flag = true;
	while(flag){
	
		int i=0;
		while(!s.empty() && i<(s.length()-1)){
			
				if(s[i] == s[i+1]){
					s.erase(i,2);
				} else 
					i++;
		
		}
		if(s.empty())
			flag = false;
		else
			flag = isNotReducible(s);
	}
	if(s.empty())
		return "Empty String";
	else
		return s;
    
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}
