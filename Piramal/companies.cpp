#include<bits/stdc++.h>
using namespace std; 
int n;
vector<vector<int> >dp;
vector<int>vis;
    vector<int>indegree;
    vector<int>depth;
    void cycle(int x,int d,int &start,int &end,int &cycle_len)
    {
        vis[x]=1;
        depth[x]=d;
        for(auto &it:dp[x])
        {
            if(vis[it]==0)
            {
                cycle(it,d+1,start,end,cycle_len);
            }
            else if(vis[it]==1)
            {
                cycle_len=max(cycle_len,depth[x]-depth[it]+1);
                start=x;
                end=it;
            }
        }
        vis[x]=2;
    }
    int maximumInvitations(vector<int>& nums) 
    {
        
        n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-1;
        }
        dp=vector<vector<int> >(n+1);
        vis=vector<int>(n+1);
        indegree=vector<int>(n+1);
        depth=vector<int>(n+1);
        for(int i=0;i<n;i++)
        {
            dp[i].push_back(nums[i]);
            indegree[nums[i]]++;
        }
        queue<int>q;
        vector<int>len(n,0);
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(q.size())
        {
            auto temp=q.front();
            vis[temp]=1;
            q.pop();
            for(auto it:dp[temp])
            {
                len[it]=len[temp]+1;
                if(--indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        int largest_cycle=0; 
        int two_cycle_and_len=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                int start=-1;
                int end=-1;
                int cycle_len=0;
                cycle(i,0,start,end,cycle_len);
                if(cycle_len==2)
                {
                    two_cycle_and_len+=(2+len[start]+len[end]);
                }
                else
                {
                    largest_cycle=max(largest_cycle,cycle_len);
                }
            }
        }
        return max(two_cycle_and_len,largest_cycle);
    }


int main(){
    vector<int> A;
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(1);
  //  A.push_back(7);
   // A.push_back(2);
    int ans=maximumInvitations(A);
    cout << ans;


}