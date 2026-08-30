#include<bits/stdc++.h>
using namespace std;

int getMaxAggregateTemperatureChange(vector<int> &tempChange)
{
    int ans = 0;
    int sum = 0;
    for(int t:tempChange)   sum+=t;
    int cur = 0;
    for(int i=0;i<tempChange.size();i++)
    {
        cur+=tempChange[i];
        int temp = max(cur,tempChange[i]+sum-cur);
        ans = max(ans,temp);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> tempChange(n);
    for(int i=0;i<n;i++)    cin>>tempChange[i];
    cout<<getMaxAggregateTemperatureChange(tempChange)<<endl;
    return 0;
}