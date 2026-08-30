/*
Max investment, array increment as per start and end idx and find max of all
SAP

*/

#include<bits/stdc++.h>
using namespace std; 
long maxValue(int n,vector<vector<int>> &rounds)

{
   
   vector<int> arr(n,0);
   int m=rounds.size();
    for (int i=0; i<m; i++)
    {
        
        int left = rounds[i][0]-1;
        int right = rounds[i][1]-1;
 
        arr[left] += rounds[i][2];
        arr[right+1] -= rounds[i][2];
    }
    long long sum = 0, res = INT_MIN;
    for (int i=0; i < n; ++i)
    {
        sum += arr[i];
        res = max(res, sum);
    }
 
    return res;
}   
    
    
int main()
{
	int n,i,j;
	cin>>n;
	cin>>i>>j;
	vector<vector<int>> rounds(i,vector<int> (j,0));
	for(int k=0;k<i;k++)
	{
		for(int z=0;z<j;z++)
		{
			cin>>rounds[k][z];
		}
	}
	cout<<maxValue(n,rounds);
}
