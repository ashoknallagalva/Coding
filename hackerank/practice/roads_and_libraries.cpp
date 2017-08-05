#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>

using namespace std;

/*void printGraph(vector<list<int> > &graph,int n){
	
	for(int i=1;i<n+1;i++){
		cout<<"node "<<i<<":";

		for (list<int>::const_iterator ci = graph[i].begin(); ci != graph[i].end(); ++ci){			
			cout<<*ci<<" ";
		}
		cout<<endl;
	}
}*/

int main(){
	
	int q;
	cin>>q;
	while(q--){
		long long cost = 0;
		int n,m,clib,croad,roads,clibs,croads,comps=0;
		cin>>n>>m>>clib>>croad;
		
		if(n==1 || m==0){
			cout<<n*clib<<endl;
			continue;
		}
		
		vector<bool> visited(n+1);
		vector<list<int> > graph(n+1);
		
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);

		}
		//printGraph(graph,n);
		
		for(int i=1;i<=n;i++){
				if(!visited[i]){
					queue<int> q;
					int tempNodes=0;
					q.push(i);
					visited[i] = true;
					//cout<<"push:"<<i<<endl;
					comps++;
					while(!q.empty()){
						int node = q.front();
						tempNodes++;
						q.pop();
						for (list<int>::const_iterator ci = graph[node].begin(); ci != graph[node].end(); ++ci){
							if(!visited[*ci]){
								q.push(*ci);
								visited[*ci] = true;
								//cout<<"push:"<<*ci<<endl;
							}
						}
						
					}
                    //cout<<tempNodes<<endl;
					cost = cost + clib;
					if(clib > croad)
						cost = cost + ((tempNodes - 1) * croad);
					else 
						cost = cost + ((tempNodes - 1) * clib);
						
				}
		}
		
		cout<<cost<<endl;
	}
	
	return 0;
}
