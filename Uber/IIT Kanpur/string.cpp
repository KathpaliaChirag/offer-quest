#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

string solution(int alpha,string beta)
{
    unordered_set<int> pos;
    for(int i=0;i<=beta.size()-alpha;i++)
    {
        char mini='z';
        int p=-1;
        bool flag = false;
        for(int j=i;j<i+alpha;j++)
        {
            if(beta[j]<=mini)
            {
                mini = beta[j];
                p = j;
                if(pos.find(p)!=pos.end())
                {   
                    flag = true;
                    break;
                }
            }
            if(flag)    break;
        }
        if(flag==false)
            pos.insert(p);
        
    }
    vector<int> ch(26,0);
    for(int s:pos)
        ch[beta[s]-'a']++;
    
    string ans = "";
    for(int i=0;i<26;i++)
    {
        while(ch[i]>0)
        {
            ans.push_back(i+'a');
            ch[i]--;
        }
    }
    return ans;
}
int main()
{
    int alpha;
    string beta;
    cin>>alpha;
    cin>>beta;
    cout<<solution(alpha,beta)<<endl;
    return 0;
}