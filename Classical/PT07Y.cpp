#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<queue>

using namespace std;

int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<list<int> > adjList(n+1);
	vector<bool> visited(n+1);
	queue<int> q;
	 
	for(int i=0;i<m;i++){
		int v1,v2;
		cin>>v1>>v2;
		adjList[v1].push_back(v2);
	}
	if(m != n-1){
			cout<<"NO"<<endl;
			return 0;
	}
	q.push(1);
	while(!q.empty()){
			int k = q.front();
			q.pop();
			if(visited[k]){
				cout<<"NO"<<endl;
				return 0;
			}
			
			for (list<int>::iterator it=adjList[k].begin(); it != adjList[k].end(); ++it){
				q.push(*it);
			}
			visited[k] = true;				
	}
	for(int i=1;i<=n;i++){
			if(!visited[i]){
				cout<<"NO"<<endl;
				return 0;
			}
	}
	cout<<"YES"<<endl;
	return 0;
}
