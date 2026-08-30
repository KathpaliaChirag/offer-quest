#include<bits/stdc++.h>
using namespace std;

int minimumGroups(vector<int> &awards,int k)
{
    sort(awards.begin(),awards.end());
    int ans = 0;
    int end = 0;
    for(int i=0;i<awards.size();i++)
    {
        if(awards[i]<=end)
            continue;
        else
        {
            ans++;
            end = awards[i]+k;
        }
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    vector<int> awards(n);
    for(int i=0;i<n;i++)    cin>>awards[i];
    cout<<minimumGroups(awards,k);
    return 0;
}