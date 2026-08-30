#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> mem;
bool isEq(char a, char b){
    if(a == b) return true;
    if(a == 'a' and b == 'o') return 1;
    if(a == 'o' and b == 'a') return 1;
    if(a == 't' and b == 'l') return 1;
    if(a == 'l' and b == 't') return 1;
    return 0;
}
int dp(string &drawString, string &ticket, int i, int j, int can_del){
    if(j == ticket.size()) return 0;
    if(i == drawString.size()){
        if(j == ticket.size()-1 and can_del == 1) return 0;
        return 1e9;
    }
    if(mem[i][j][can_del] != -1) return mem[i][j][can_del];
    int ans = 1e9;
    if(isEq(drawString[i], ticket[j])) ans = min(ans, dp(drawString, ticket, i+1, j+1, can_del));
    ans = min(ans, 1 + dp(drawString, ticket, i+1,j,can_del));
    if(can_del == 1){
        ans = min(ans, dp(drawString, ticket, i, j+1, 0));
    }
    return mem[i][j][can_del] = ans;
}
int main() {
    int n; cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    string ds; cin>>ds;
    int tol; cin>>tol;
    int ans = 0;
    for(string c : v) {
        mem.assign(ds.size(), vector<vector<int>> (c.size(), vector<int> (2,-1)));
        for(int j=0;j<ds.size();j++){
            if(dp(ds, c, j, 0, 1) <= tol){
                ans++;
                break;
            }
        }
    }
    cout << ans;
}