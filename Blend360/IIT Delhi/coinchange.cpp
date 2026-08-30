int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int max_am=1e4+1;
        vector<vector<int>> dp(n+1,vector<int>(amount+1,max_am));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        if(dp[n][amount]!=max_am){
            return dp[n][amount];
        }
        return -1;
    }