using namespace std;
#define ll long long
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;
int g[101][101];
vector<vector<int>>d;
int dp[16][(1<<15)+5];
vector<int> e_s;

int dfs(int mask,int pos){
    if(mask==(1<<m)-1) return e_s[pos];
    if(dp[pos][mask]!=-1) return dp[pos][mask];

    int ans=2e9;

    for(int i=0;i<m;i++){
        if(!(mask&(1<<i))){
            int temp = d[pos][i] + dfs(mask|(1<<i),i);
            ans=min(ans,temp);
        }
    }
    return dp[pos][mask]=ans;
}

vector<int> fun(int sx,int sy,vector<pair<int,int>>&ch){
    queue<pair<int,int>> pq;
    vector<vector<int>> dist(n+1,vector<int>(n+1,1e9));
    dist[sx][sy]=0;

    pq.push({sx,sy});
    while(!pq.empty()){
        pair<int,int> t=pq.front();pq.pop();
        int x=t.first,y=t.second;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n && g[nx][ny]!=1){
                if(dist[nx][ny]>dist[x][y]+1){
                    dist[nx][ny]=dist[x][y]+1;
                    pq.push({nx,ny});
                }
            }
        }
    }
    
    vector<int> ans;
    for(auto i:ch){
             if(dist[i.first][i.second]==1e9) return {-1,-1};
             else ans.push_back(dist[i.first][i.second]);
    }
    return ans;
}


void solve() {
    n;cin>>n;
    vector<pair<int,int>> ch;
    ch.push_back({0,0});
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
            if(g[i][j]==2)ch.push_back({i,j});
        }
    }

    int ex,ey;cin>>ex>>ey;
    m = ch.size();
    
    for(int i=0;i<m;i++){
        vector<int>a1=fun(ch[i].first,ch[i].second,ch);
        if(a1[0]==-1) {cout<<"-1"<<endl;return;}
        d.push_back(a1);
    }

    e_s = fun(ex,ey,ch);
    if(e_s[0]==-1) {cout<<"-1"<<endl;return;}
    memset(dp,-1,sizeof(dp));
    cout<<dfs(1,0)<<endl;
}