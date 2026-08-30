#include<bits/stdc++.h>
using namespace std;
int dp[505];
int solve(int i,vector<int> &arr,int n,int k){
	
	if(i>=n){
	return 0;
	}
	if(dp[i]!=-1){
	return dp[i];
	}
	int ans=INT_MAX;
	int mx=0;
	for(int j=i;j<min(i+k,n);j++){
		//this will take care of the case to include it.
		mx=max(mx,arr[j]);
		//partition this array here.
		int temp=mx+solve(j+1,arr,n,k);
		ans=min(ans,temp);

	}
	return dp[i]=ans;

}
int main(){

	int n;
	cin>>n;
	vector<int> arr(n);
	
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	int threshold;
	cin>>threshold;
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,arr,n,threshold)<<endl;
	return 0;
}