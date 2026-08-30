/*
Given an array of n elements and a number 'k', find all possible ways to produce the sum = k, where each elements are infinite supplies
but no duplicate sets allowes ex: (1,6), (6,1)
Sample Input
arr ={1,2}
k= 6

Sample output
4

Expln: 
1 1 1 1 1 1
1 1 1 1 2
1 1 2 2
2 2 2

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void nWaysCoins(int coins[], int n, int sum)
{
	vector<vector<int>> dp(n, vector<int> (sum+1)); // or int dp[n][sum+1];
	//First col
	for(int i=0;i<n;i++)
		dp[i][0]=1;
		
	//Firt row
	for(int i=1;i<sum+1;i++)
	{
		if(i%coins[0]==0)
		{
			dp[0][i]=1;
		}
		else // sum can't be formed with coins[0], 0 ways
			dp[0][i]=0;
	}
	
	//Other cells
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(coins[i]>j)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]];
		}
	}
	
	
	if(dp[n-1][sum]!=0)//Soln exists
	{
		cout<<"\n No. of Ways:"<<dp[n-1][sum]<<endl;
	}
	
	//Print dp table
	cout<<"\nPrint dp table";
	for(int i=0;i<n;i++)
	{
		cout<<endl;
		for(int j=0;j<sum+1;j++)
		cout<<dp[i][j]<<"  ";
	}
	
	
	
}
int main()
{
	 int coins[] =  {1,2};
	
    int m = sizeof(coins)/sizeof(coins[0]); 
    //soring is must
    sort(coins,coins+m);
    int V;
    cin>>V; 
    nWaysCoins(coins, m, V); 
    
    return 0; 

}
