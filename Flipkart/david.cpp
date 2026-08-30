#include<bits/stdc++.h>
using namespace std;
int main(){


	int target;
	cin>>target;
	vector<int> arr;
	int i=1;
	while (i*i<=2500){
		arr.push_back(i*i);
		i++;
	}
	//question based on unbounded knapsack 
	int n=arr.size();
	int mod=1e9+7;
	vector<vector<int>> dp(n+1, vector<int> (target+1,0));
	for(int i=0;i<=n;i++){
		dp[i][0]=1;

	}

	for(int i=1;i<=n;i++){
		for(int j=0;j<=target;j++){
			if(arr[i-1]<=j){
				dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];
							}
			else{
				dp[i][j]=dp[i-1][j];
			}
			dp[i][j]=dp[i][j]%mod;

		}
	}
	cout<<dp[n][target]%mod<<endl;

	return 0;
}