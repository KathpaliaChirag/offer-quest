#include<bits/stdc++.h>
using namespace std;

vector<int> findDataLocations(vector<int> &locations,vector<int> &movedFrom,vector<int> &movedTo)
{
    map<int,int> mp;
    for(int i:locations)    mp[i]=1;
    for(int i=0;i<movedFrom.size();i++)
    {
        mp.erase(movedFrom[i]);
        mp[movedTo[i]]++;
    }
    vector<int> ans;
    for(auto it:mp)
        ans.push_back(it.first);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> locations(n);
    vector<int> movedFrom(m);
    vector<int> movedTo(m);
    for(int i=0;i<n;i++)    cin>>locations[i];
    for(int i=0;i<m;i++)    cin>>movedFrom[i];
    for(int i=0;i<m;i++)    cin>>movedTo[i];
    vector<int> ans = findDataLocations(locations,movedFrom,movedTo);
    for(int a:ans)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}