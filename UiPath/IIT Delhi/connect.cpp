#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
void bfs(vector<int> &visited,int src){
	visited[src]=true;
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int aux=q.front();
		q.pop();
		for(auto out: adj[aux]){
			if(visited[out]==false){
				q.push(out);
				visited[out]=true;
			}
		}
	}
}
int main(){


	int n;
	cin>>n;
	int edges;
	cin>>edges;
	adj.resize(n+1);
	vector<int> indegree(n+1,0);
	for(int i=0;i<edges;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	
	int capital;
	cin>>capital;
	vector<int> visited(n+1,0);
	bfs(visited,capital);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(visited[i]==false and indegree[i]==0){
			bfs(visited,i);
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}