// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int res=0;

int solve(int ind, vector<int>&nums, vector<int>&dp){
    if(ind>=nums.size()){
        return 0;
    }
    if(dp[ind]!=-1) return dp[ind];
    
    int mini=INT_MAX;
    for(int i=ind;i<nums.size();i++){
        mini=min(mini, nums[i]);
        int temp= mini*(i-ind+1);
        res = max(res, temp);
        //cout<<res<<endl;
        solve(i+1, nums, dp);
    }
    
    return dp[ind]=res;
}

int main() {
    
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>dp(n+1, -1);
    cout<<solve(0, nums, dp);
    return 0;
}