#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u;
	int v;
	int wt;
	node(int first,int second,int weight){
		u=first;
		v=second;
		wt=weight;
	}
};
bool comp(node a,node b){
	return a.wt<b.wt;
}
int find_parent(int u,vector<int> &parent){
	if(u==parent[u]){
		return u;
	}
	return parent[u]=find_parent(parent[u],parent);
}
void unionn(int u,int v,vector<int> &parent,vector<int> &rank){
	u=find_parent(u,parent);
	v=find_parent(v,parent);
	if(rank[u]<rank[v]){
		parent[u]=v;
	}
	else if(rank[u]>rank[v]){
		parent[v]=u;
	}
	else{
		parent[v]=u;
		rank[u]++;
	}
}

long long solution(int n,vector<long long> a,vector<long long> r){
	vector<node> edges;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			edges.push_back(node(i,j,a[i]*r[j]));
			edges.push_back(node(i,j,r[i]*a[j]));

		}
	}
	sort(edges.begin(),edges.end(),comp);
	vector<int> parent(n);
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
	vector<int> rank(n,0);
	long long cost=0;
	for(auto it:edges){
		if(find_parent(it.v,parent)!=find_parent(it.u,parent)){
			cost+=it.wt;
			//cout<<cost<<endl;
			unionn(it.u,it.v,parent,rank);
		}
	}
	return cost;
}
int main(){
	
	int n;
	cin>>n;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<long long> r(n);
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	cout<<solution(n,a,r)<<endl;



}