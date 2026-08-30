#include<bits/stdc++.h>
using namespace std;

int getMinimumCost(vector<int> &parcels,int k)
{
    vector<int> hashTable(2000001,0);
    for(int p:parcels)  hashTable[p]=1;
    int parcel = 1;
    int cost = 0;
    int need = k-parcels.size();
    while(need--)
    {
        while(hashTable[parcel]==1) parcel++;
        cost+=parcel++;
    }
    return cost;
}
int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    vector<int> parcels(n);
    for(int i=0;i<n;i++)    cin>>parcels[i];
    cout<<getMinimumCost(parcels,k);
    return 0;
}