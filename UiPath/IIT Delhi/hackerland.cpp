#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N;
	cin >> N;
	vector<node> edges; 
	vector<int> arr(N);
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	//cout<<" hello"<<endl;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			edges.push_back(node(arr[i],arr[j],-(arr[i]^arr[j])));
			edges.push_back(node(arr[j],arr[i],-(arr[i]^arr[j])));


		}
	}
	//cout<<"I am here"<<endl;
	//sort edges by weights
	sort(edges.begin(), edges.end(), comp); 
	//Use the concept of Disjoint set union
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; 

	vector<int> rank(N, 0); 
	
	int cost = 0;
	vector<pair<int,int>> mst; 
	for(auto it : edges) {
		//if parents are different they belong to different component so it will be included in the answer and do union
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << -1*cost << endl;
	//for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}