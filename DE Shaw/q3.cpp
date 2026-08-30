long countRouteCycles(int tree_nodes, vector<int> tree_from, vector<int> tree_to, vector<int> colors) {
    int n = tree_nodes;
    vector<vector<int>> adj(n+1);

    int m = tree_from.size();
    for(int i = 0; i < m; i++){
        int u = tree_from[i];
        int v = tree_to[i];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1,false);
    long answer = 0;

    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        int col = colors[i-1];       
        long sz = 0;       

        stack<int> st;
        st.push(i);

        vis[i] = true;

        while(!st.empty()){
            int u = st.top(); st.pop();
            sz++;

            for(int w : adj[u]){
                if(!vis[w] && colors[w-1] == col){
                    vis[w] = true;
                    st.push(w);
                }
            }
        }
        
        if(sz >= 3){
            answer += (sz - 1) * (sz - 2) / 2;
        }
    }
    return answer;
}