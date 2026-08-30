#include <bits/stdc++.h>

using namespace std;


int solve(string &s)
{
    int n=s.size();
    for(int i=2;i<n;i++){
        
        if(s[i]!='?')
            continue;
            
        if(s[i-1]==s[i-2] && s[i-1]!='?')
            s[i] = s[i-1]=='a'?'b':'a';
            
    }
    
    for(int i=n-3;i>=0;i--){
        
        if(s[i]!='?')
            continue;
            
        if(s[i+1]==s[i+2] && s[i+1]!='?')
            s[i] = s[i+1]=='a'?'b':'a';
            
    }
    
    for(int i=1;i<n-1;i++){
        if(s[i]!='?')
            continue;
        if(s[i-1]==s[i+1] && s[i-1]!='?')
            s[i] = s[i-1]=='a'?'b':'a';
    }
    
    bool flag=true;
    for(int i=0;i<n;i++){
        if(s[i]!='?')
            continue;
        if(flag)
            s[i]='a';
        else
            s[i]='b';
        flag=!flag;
    }
    
    return 0;
}
int main()
{
    string s;
    cin>>s;
    solve(s);
    cout<<s;
    return 0;
}

