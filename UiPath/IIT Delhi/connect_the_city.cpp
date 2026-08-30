#include<bits/stdc++.h>
using namespace std;
void bfs(int c,vector<int> graph[],vector<int> &visited){
	queue<int> q;
	q.push(c);
	visited[c]=1;
	while(!q.empty()){
		int aux=q.front();
		q.pop();
		for(auto out: graph[aux]){
			if(visited[out]==0){
				q.push(out);
				visited[out]=1;
			}
		}
	}



}
int get_minimum(int n,vector<int> graph[],vector<int> &visited,int c,vector<int> &indegree){
	//step 1 bfs traversal to find the nodes connected to the king city, that can be reached directly.
	
	
	bfs(c,graph,visited);
	//step 2 find the vertex with one degree and join them so that rest component is joined
	int count=0;
	for(int i=0;i<n;i++){
		if(indegree[i]==0 and visited[i]==0){
			bfs(i,graph,visited);
			count++;
		}

	}
	// step3 find the cyclic component
	for(int i=0;i<n;i++){
		if(visited[i]==0){
			bfs(i,graph,visited);
			count++;
		}
	}
	return count;


}
int main(){

	int n;
	int m;
	cin>>n>>m;
	vector<int> indegree(n+1,0);
	vector<int> graph[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		indegree[v]++;
	}
	int king;
	cin>>king;
	vector<int> visited(n+1,0);
	cout<<get_minimum(n,graph,visited,king,indegree)-1<<endl;
	return 0;
}