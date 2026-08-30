#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a,b,k;
	cin>>a>>b>>k;
	int edges,r;
	cin>>edges>>r;
	vector<pair<int,int>> graph[n];
	for(int i=0;i<edges;i++){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	vector<int> dist(n,1e9);
	dist[a]=0;
	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
	pq.push({0,a,k});
	while(!pq.empty()){

		vector<int> temp=pq.top();
		pq.pop();
		int dis=temp[0];
		int u=temp[1];
		int k=temp[2];
		for(int i=0;i<graph[u].size();i++){
			int v=graph[u][i].first;
			int new_dist=dis+graph[u][i].second;
			//if considered
			if(new_dist<dist[v]){
				dist[v]=new_dist;
				pq.push({new_dist,v,k});
			}
			//if spell is used
			if(k>0){
				int new_dist=dis+0;
				if(new_dist<dist[v]){
					dist[v]=new_dist;
					pq.push({new_dist,v,k-1});
				}
			}
		}



	}
	if(dist[b]==1e9){
		cout<<-1<<endl;
	}
	cout<<dist[b]<<endl;


	return 0;
}