#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string solve(string x, string y){
        
        int n=x.size();
        int m=y.size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        for(int i=0;i<m+1; i++){
            dp[0][i]=0;
        }
        for(int i=0;i<n+1; i++){
            dp[i][0]=0;
        }
        
        for(int i=1;i<n+1; i++){
            for(int j=1;j<m+1;j++){
                
                if(x[i-1]==y[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=m;j++){
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        int maxi = INT_MIN;
        string ans="";
        for(int i=0;i<n+1; i++){
            for(int j=0;j<m+1; j++){
                
                if(dp[i][j]>maxi){
                    
                    string temp = x.substr(i-dp[i][j], dp[i][j]);
                    string rev = temp;
                    reverse(rev.begin(), rev.end());
                    if(temp==rev){
                        ans=temp;
                        maxi=dp[i][j];
                    } 
                }
            }
        }
        return ans;
    }
    
    int main(){
        string s;
        cin>>s;
        string x=s;
        reverse(s.begin(), s.end());
        string y=s;
        cout<< solve(x, y);
        return 0;
    }