#include<bits/stdc++.h>
using namespace std;

int findEarliestMonth(vector<int> &stockPrices)
{
    int mini = INT_MAX;
    int ans;
    int sum = 0;
    for(int s:stockPrices)  sum+=s;
    int cur = 0;
    int n = stockPrices.size();
    for(int i=0;i<n-1;i++)
    {
        cur+=stockPrices[i];
        int val = abs(cur/(i+1)-(sum-cur)/(n-i-1));
        if(val<mini)
        {
            mini = val;
            ans = i+1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> stockPrices(n);
    for(int i=0;i<n;i++)
        cin>>stockPrices[i];
    cout<<findEarliestMonth(stockPrices)<<endl;
}