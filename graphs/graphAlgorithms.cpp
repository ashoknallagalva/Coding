#include<iostream>
#include<queue>
#include<vector>
#include<list>


using namespace std;

vector<bool> visited(100000);

void resetVisited(int n){
	for(int i=1;i<=n;i++)
		visited[i] = false;
}
void bfs(vector<list<int> > &graph,int n,int start){
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while(!q.empty()){
			int node = q.front();
			cout<<node<<" ";
			q.pop();
			for(list<int>::const_iterator ci = graph[node].begin();ci!=graph[node].end();++ci){
				if(!visited[*ci]){
					visited[*ci] = true;
					q.push(*ci);
				}
			}
	}
	cout<<endl;
	
}

void dfs(vector<list<int> > &graph,int start){
	
	visited[start] = true;
	cout<<start<<" ";
	for(list<int>::const_iterator ci = graph[start].begin();ci!=graph[start].end();++ci){
		if(!visited[*ci]){
			dfs(graph,*ci);
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<list<int> > graph(n+1);
		
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	resetVisited(n);
	cout<<"bfs :";
	bfs(graph,n,1);
	resetVisited(n);
	cout<<"dfs :";
	dfs(graph,1);
	cout<<endl;
	
	return 0;
	
}
