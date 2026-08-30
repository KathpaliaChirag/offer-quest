#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> boxTypes{{5,10},{2,5},{4,7},{3,9}}; //[[1,3],[2,2],[3,1]] // [[5,10],[2,5],[4,7],[3,9]]
    int truckSize=13;
    int count=0;
    vector<int> v;
    map<int, int> map;

    for (auto i : boxTypes)
    {
        map[i[1]] = i[0];
    }
    for (auto i = map.rbegin(); i != map.rend(); i++)
    {
       cout<<i->first<<"->"<<i->second<<endl;
    }
    for (auto i = map.rbegin(); i != map.rend(); i++)
    {
         if(truckSize - i->second>=0){
            
             count+= i->second*i->first;
             truckSize-=i->second;
           //   cout<<"this is map"<<i->first<<" and truckSize is "<<truckSize<<"and count"<<count<<endl;
            // map.erase(i->first);
             
         }
         else{
             while(truckSize>0){
               //  cout<<"this is map"<<i->first<<" and truckSize is "<<truckSize<<"and count"<<count<<endl;
                 count+=i->first;
                 i->second-=1;
                 truckSize--;
                 if(i->second == 0){
                     map.erase(i->first);
                 }
             }
         }
    }
    
    cout<<count<<endl;
	return 0;
}
