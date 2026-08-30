#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int> indegree;
int len = 0;

void kahns(int n, vector<int>& vis){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int u = q.front(); q.pop(); len++; vis[u] = 1;
        for(auto v : adj[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }
}

int bfs(int src, vector<int>& vis){
    queue<int> q;
    q.push(src);
    int cnt = 0;
    while(!q.empty()){
        int u = q.front(); q.pop(); vis[u] = 1; cnt++;
        for(auto v : adj[u]){
            if(vis[v] == 0){
                q.push(v);
            }
        }
    }
    return cnt-1;
}

int main() {
    int n; cin>>n;
    int e; cin>>e;
    adj.resize(n+1);
    indegree.resize(n+1, 0);
    
    for(int i=0; i<e; i++){
        int u; int v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    vector<int> vis(n+1, 0);
    kahns(n, vis);
    
    for(int i=1; i<=n; i++){
        if(vis[i] == 0){
            int temp = bfs(i, vis);
            len = len + temp;
        }
    }
    cout<<len<<endl;
    return 0;
}
