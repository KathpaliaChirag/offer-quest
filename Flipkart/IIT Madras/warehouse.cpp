#include <iostream>
#include<vector>
using namespace std;
int answer(vector<vector<int> >& dist,vector<int>& warehouse)
{
 int n = dist.size();
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    int min_cost=1e9;
    int m = warehouse.size();
    for(int i=0;i<m-1;i++)
    {
        for(int j=i+1;j<warehouse.size();j++) 
   min_cost=min(min_cost,dist[warehouse[i]][warehouse[j]]);
    }
    return min_cost;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> warehouse;
    while(m--)
    {
        int t;
        cin>>t;
        warehouse.push_back(t);
    }
    int e;
    cin>>e;
    vector<vector<int> > dist(n,vector<int> (n,1e9));
    for(int i=0;i<n;i++) dist[i][i]=0;
    while(e--)
    {
        int i,j,c;
        cin>>i>>j>>c;
        dist[i][j]=c;
        dist[j][i]=c;
    }
    cout<<answer(dist,warehouse)<<endl;
 return 0;
}
