#include<bits/stdc++.h>
using namespace std;



struct node {int a,b,c;};

void solve()
{
    int n;
    cin>>n;
    vector<node>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i].a>>arr[i].b>>arr[i].c;
    sort(arr.begin(),arr.end(),[](node &t, node &s)->bool
    {
        if(s.a > t.a)
            return 1;
        else if(t.a > s.a)
            return 0;
        else
        {
            if(s.b > t.b)
                return 1;
            else if(t.b > s.b)
                return 0;
            else
            {
                if(s.c > t.c)
                    return 1;
                else
                    return 0;
            }
        }
    });
    int dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = arr[0].b-arr[0].a+arr[0].c;
    for(int i=1;i<n;i++)
    {
        int far = -1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i].a >= arr[j].b)
            {
                far = j;
                break;
            }
        }
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        if(far == -1)
            dp[i][1] = arr[i].b - arr[i].a + arr[i].c;
        else
            dp[i][1] = max(dp[far][0],dp[far][1]) + arr[i].b - arr[i].a + arr[i].c;
    }
    int max_ = -1;
    for(int i=0;i<n;i++)
        max_ = max({dp[i][0],dp[i][1],max_});
    cout<<max_<<endl;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}