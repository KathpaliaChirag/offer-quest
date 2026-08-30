#include <bits/stdc++.h>

using namespace std;

bool check(vector<string>&B, vector<vector<bool>>&visited,vector<vector<bool>>&guards, int ar, int ac)
{
    // cout<<ar<<" "<<ac<<endl;
    
    
    int r=B.size(),c=B[0].size();
    
    if(ar>r-1 || ar<0 || ac<0 || ac>c-1 || !(B[ar][ac]=='.' || B[ar][ac]=='A') || visited[ar][ac])
        return false;
      
    visited[ar][ac]=true;
    
    if(guards[ar][ac])
        return false;
        
    if(ar==r-1 && ac==c-1)
        return true;
        
    int arr[5]={0,1,0,-1,0};
    
    for(int i=0;i<4;i++){
        
        // cout<<ar<<" "<<ac<<" ; check "<<i<<endl;
        
        int x=ar+arr[i],y=ac+arr[i+1];
        
        if(check(B,visited,guards,x,y))
            return true;
        
        // cout<<ar<<" "<<ac<<" ; check "<<i<<" ; false"<<endl;
            
    }
    
    return false;
}

bool solution(vector<string>&B)
{
    int r=B.size(),c=B[0].size();
    
    vector<vector<bool>>visited(r,vector<bool>(c,false));
    vector<vector<bool>>guards(r,vector<bool>(c,false));
    int ar=0,ac=0;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            
            if(B[i][j]=='A'){
                ar=i;ac=j;
            }
            
            else if(B[i][j]=='<'){
                int k=j-1;
                while(k>=0){
                    
                    if(B[i][k]=='A')
                        return false;
                    else if(B[i][k]!='.')
                        break;
                    guards[i][k]=true;
                    k--;
                }
            }
            
            else if(B[i][j]=='>' ){
                int k=j+1;
                while(k<c ){
                    
                    if(B[i][k]=='A')
                        return false;
                    else if(B[i][k]!='.')
                        break;
                        
                    guards[i][k]=true;
                    k++;
                }
            }
            
            else if(B[i][j]=='^'){
                int k=i-1;
                while(k>=0){
                    
                    if(B[k][j]=='A')
                        return false;
                    else if(B[k][j]!='.')
                        break;
                        
                    guards[k][j]=true;
                    k--;
                }
            }
            
            else if(B[i][j]=='v'){
                int k=i+1;
                while(k<r){
                    
                    if(B[k][j]=='A')
                        return false;
                    else if(B[k][j]!='.')
                        break;
                        
                    guards[k][j]=true;
                    k++;
                }
            }
        }
    }
    
    return check(B,visited,guards,ar,ac);
    
}

int main()
{
    int n;
    vector<string>input;
    cout<<"Enter num of rows"<<endl;
    cin>>n;
    cout<<"Enter strings"<<endl;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        input.push_back(s);
    }
    
    
    if(solution(input))
        cout<<"True";
    else
        cout<<"False";
    return 0;
}
