                                     
#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int solve(int i,vector<int> &arr,int b,vector<int> &prefix,int n){

	if(i>=n and b==0){
		return 0;
	}
	if(i>=n or b==0){
		return INT_MAX;
	}
	if(dp[i][b]!=-1){
		return dp[i][b];
	}
	int ans=INT_MAX;

	for(int j=i;j<n;j++){
		int sum=0;
		if(i==0){
			sum=prefix[j];
		}
		else{
			sum=prefix[j]-prefix[i-1];
		}
		int left=solve(j+1,arr,b-1,prefix,n);
		int temp=sum*sum+left;
		ans=min(ans,temp);
	}
	return dp[i][b]=ans;

}
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		//cout<<arr[i]<<endl;
	}
	int b;
	cin>>b;
	vector<int> prefix(n,arr[0]);
	for(int i=1;i<n;i++){
		prefix[i]=prefix[i-1]+arr[i];
		//cout<<prefix[i]<<endl;
	}
	memset(dp,-1,sizeof(dp));
	int res=solve(0,arr,b,prefix,n);
	cout<<res<<endl;
	return 0;
}