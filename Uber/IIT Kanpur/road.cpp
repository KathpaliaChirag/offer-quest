
#include<bits/stdc++.h>
using namespace std;

// int solution(int n, vector<int> start, vector<int> finish) {
//     vector<pair<int,int>>v;
//     for(int i=0;i<start.size();i++)
//     {
//         v.push_back({start[i],finish[i]});
//     }
//     sort(v.begin(),v.end());
//     for(auto x:v){
//         cout<<x.first<<" "<<x.second<<endl;
//     }
//     int ans=0;
//     for(int i=1;i<v.size();i++)
//     {  
//         ans=max(ans,v[i].first-v[i-1].second-1);
//     }
//     return ans;
// }


int solution(int n,vector<int> start,vector<int> finish){


    vector<int> ans(n+1,0);
    int m=start.size();
    for(int i=0;i<m;i++){
        ans[start[i]]++;
        ans[finish[i]+1]--;
    }
    for(int i=1;i<=n;i++){
        ans[i]+=ans[i-1];
    }
    for(int i=0;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
int main(){
    int n=10;
    vector<int> start={4,1,2,6,6};
    vector<int> finish={4,4,4,10,8};
    cout<<solution(n,start,finish)<<endl;
}