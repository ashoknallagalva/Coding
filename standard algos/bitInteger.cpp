//big integer operations on vector of short 
//and it includes string of integer to vector of short convertion functions also

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//return true if a is greater than b. else returns false
bool compare(vector<short> &a, vector<short> &b){
	if(a.size() > b.size())
		return true;
	else if(a.size() < b.size())
		return false;
	else{
		int size = a.size();
		
		for(int i=0;i<size;i++){
			if(a[i] > b[i]))
				return true;
			else if(a[i] < b[i])
				return false;
		}
		return false;
	}
}

void bigIntSub(vector<short> &x, vector<short> &y, vector<short> &res){
	
	vector<short> &a = compare(x,y)?x:y, &b = compare(x,y)?y:x;
	
	int br = 0,ai = a.size() - 1;
	for(int bi = b.size()-1;bi>=0;bi--,ai--){
		int sub;
		if((a[ai] - br) < b[bi]){
			sub = ((a[ai] - br) * 10) - b[bi];
			br = 1;
		} else {
			sub = (a[ai] - br) - b[bi];
			br = 0;
		}
		res.push_back(sub);
	}
	res.push_back(a[ai] - br);
	br = 0;
	ai--;
	while(ai>=0){
		res.push_back(a[ai]);
		ai--;
	}
	reverse(res.begin(),res.end());
}

// performs x / y
void bigIntDiv(vector<short> &x, vector<short> &y, vector<short> &res){
	
}
