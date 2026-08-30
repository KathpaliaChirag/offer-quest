#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200002;
int n;
//arr is store the a array
//total is used to store the sum of all arr
//ans to specify the ans
ll arr[maxn],total,ans;
//store the graph in adjacency list
vector<int> graph[maxn];

//subtotal is store the di*ai for all the vertices i in the subtree of u. di=distance between u and i.
//sum is store the subtree sum inluding itself.
ll subtotal[maxn],sum[maxn];
//dfs to calculate the sutotal and sum
//use dfs recursively to calculate all the sum
void dfs(int u,int p){
	subtotal[u]=0LL;
	sum[u]=arr[u];
	for(int v:graph[u]){
		if(v!=p){
			dfs(v,u);
			sum[u]+=sum[v];
			subtotal[u]+=(subtotal[v]+sum[v]);
		}
	}
}
//now if choose any vertex u which is in the subtree if vertex u will not change. other vertices which are not in the subtree of vertex u will change. let up store the all other vertices which are not in the subtree u be up.
/*
Notice that, the calculation for any vertex which is in the subtree of vertex u will not change. What will be changed? Other vertices which is not in the subtree of vertex u. Lets the sum of all subtot[] values of other vertices which are not in 
the subtree of vertex u be up. Every time you go one step down, distance from vertex u to all other vertices which are not in the subtree of vertex u will increase by 1. So, wee need to increase up by tot - sum[u](we are ignoring the sum[u], 
since distance to other nodes is increased, which is, sum of all a[i], for all vertex i which are not in the subtree of vertex u.)

Then the current answer for vertex u is cur = subtot[u] + up + tot - sum[u]. Here, subtot[u] is for for vertices in the subtree of u, up for vertices which are not in the subtree, tot-sum[u] is for increasing ditance by 1 for non subtree vertices.

Then the current answer for vertex u is cur = subtot[u] + up + tot - sum[u]. Here, subtot[u] is for for vertices in the subtree of u, up for vertices which are not in the subtree, tot-sum[u] is for increasing ditance by 1 for non subtree vertices.

When you will go to vertex v from vertex u, then update up by up = cur - subtot[v] - sum[v]. Here since we are going down, that's why we subtract subtot[v] and sum[v], instead of adding.

Thus, you have to run another dfs to try to choose each vertex as the fixed vertex and keep track of the maximum value cur ans our required answer in ans.





*/
void dfs2(int u,int p,ll up){
	ll cur=subtotal[u]+up+total-sum[u];
	ans=max(ans,cur);
	for(int v:graph[u]){
		if(v!=p){
			dfs2(v,u,cur-subtotal[v]-sum[v]);
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		total+=arr[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1,0);
	dfs2(1,0,0LL);
	cout<<ans<<endl;
	return 0;
}