#include <bits/stdc++.h>
using namespace std;

int djikstra(vector<vector<vector<int>>>& adj, int r, unordered_set<int> &st){
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[r]=0;
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    for(auto x : adj[r]){
        pq.push(x);
        dist[x[1]] = x[0];
    }
    int min_dis = INT_MAX;
    while(!pq.empty()){
        auto tp = pq.top();
        pq.pop();
        if(st.find(tp[1])!=st.end()){
            min_dis = min(min_dis, dist[tp[1]]);
            break;
        }
        for(auto x : adj[tp[1]]){
            if(dist[tp[1]]+x[0]<dist[x[1]]){
                dist[x[1]]=dist[tp[1]]+x[0];
                pq.push({dist[x[1]], x[1]});
            }
        }
    }
    return min_dis;
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> arr(k);
    unordered_set<int> st;
    for(int i=0; i<k; i++){
        cin>>arr[i];
        st.insert(arr[i]);
    }
    int t;
    cin>>t;
    vector<vector<vector<int>>> adj(n, vector<vector<int>>());
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    int ans = INT_MAX;
    for(int x : arr){
        ans = min(ans, djikstra(adj, x, st));
    }
    cout<<ans<<endl;
    return 0;
    
}