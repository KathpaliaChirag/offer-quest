#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int go(vector<int>& a,int i, int prev,vector<vector<int> > & dp){
    if(i>=a.size()){
        return 1;
    }
    if(prev!=-1){
        if(dp[i][prev]!=-1) return dp[i][prev];
    }
    if(i==0){
        int ans=0;
        for(int j=0;j<=a[i];j++){
            ans+=go(a,i+1,j,dp);
        }
        return ans;
    }
    int ans=0;
    for(int j=prev;j<=a[i];j++){
        if(a[i-1]-prev>=a[i]-j){
            ans+=go(a,i+1,j,dp);
        }
    }
    return dp[i][prev]=ans;
}

int solve(vector<int>& nums,int n){
    vector<vector<int> > dp(n,vector<int>(n,-1));
    return go(nums,0,-1,dp);
}

int main(){

    int n;
    cin >> n;

    vector<int> nums;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int ans=solve(nums,n);
    cout << ans;
    return 0;
}