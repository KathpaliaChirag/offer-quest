#include<bits/stdc++.h>
using namespace std;

int minimizeMemory(vector<int> &processes,int m)
{
    int total = 0;
    for(int mem:processes)  total+=mem;

    int sum = 0;
    int maxi = 0;
    for(int i=0;i<processes.size();i++)
    {
        if(i<m-1)
            sum+=processes[i];
        else
        {
            sum+=processes[i];
            maxi = max(maxi,sum);
            sum-=processes[i-m+1];
        }
    }
    return total-maxi;
}
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    vector<int> processes(n);
    for(int i=0;i<n;i++)
        cin>>processes[i];
    cout<<minimizeMemory(processes,m);
    return 0;
}