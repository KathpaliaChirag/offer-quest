#include <bits/stdc++.h>
using namespace std;
 
#define M 1000000007
/*This problem can be solved with the following recurrence: Let dp[i][j] be the number of ways to use the first i letters of s to end up at position j.

Base case: dp[0][x] = 1. All else is 0.
Recurrence: Set dp[i][j] = dp[i-1][j] (corresponds to don't use current character). Then, if s[i] (1-indexed) is l, add dp[i-1][j+1] (assuming j+1 <= n). Otherwise, add dp[i-1][j-1] (assuming j-1 >= 0).
Answer: The answer is dp[s.length][y].
*/ 
int solve(string s,int n,int x,int y){
    vector<int> prev_same(s.length());
    int idx_left=-1;
    int idx_right=-1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='l'){
            prev_same[i]=idx_left;
            idx_left=i;
        }
        else{
            prev_same[i]=idx_right;
            idx_right=i;
        }
    }
    vector<vector<int>> dp(s.length()+1,vector<int>(n+1,0));
    dp[0][x]=1;
    for(int i=1;i<=s.length();i++){
        for(int j=0;j<=n;j++){
            //doesn't include i the character
            dp[i][j]=dp[i-1][j];
            if(s[i-1]=='l'){
                if(j+1<=n ){
                    dp[i][j]+=dp[i-1][j+1];
                }
                if(j+1<=n and prev_same[i-1]>=0){
                    dp[i][j]-=dp[prev_same[i-1]][j+1];
                }

            }
            else{
                if(j-1>=0 ){
                    dp[i][j]+=dp[i-1][j-1];

                }
                if(j-1>=0 and prev_same[i-1]>=0){
                    dp[i][j]-=dp[prev_same[i-1]][j-1];
                }
            }
            dp[i][j]=(dp[i][j]+M)%M;
        }
    }
    return int(dp[s.length()][y]);

}


 
int main() {
	string step;
	cin >> step;
	int n,s,e;
	cin >> n >> s >> e;
	cout << solve( step, n, s, e ) << "\n";
	return 0;
}