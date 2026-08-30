#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void countTeams(int num,vector<int> skills, int minAsso,int i, set<vector<int>> &subarrays, vector<int> &out){
   if (skills.size() == 0 || skills.size() < minAsso) {
        return ;
    }
    if ( minAsso== 0) {
        subarrays.insert(out);
        return;
    }
 
   
    for (int j = i; j < skills.size(); j++)
    {
        out.push_back(skills[j]);
        countTeams(num,skills, minAsso-1,j + 1, subarrays, out);
        out.pop_back();        // backtrack
    }
   return;
  
}


int main() {
int n;
cin>>n;
vector<int> v;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
}
int minAsso,minLev,maxLev;
cin>>minAsso>>minLev>>maxLev;
  vector<int> emp;
   for(int i=0;i<n;i++){
       if(v[i]>=minLev and v[i]<= maxLev){
           emp.push_back(v[i]);
       }
       
   }   

 set<vector<int>> subarrays;
 vector<int> out;
 int loop = emp.size()-minAsso;
 
 for(int i=0;i<=loop;i++){
   //  cout<<"min asso with :"<<minAsso+i<<endl;
 countTeams(n,emp,minAsso+i,0,subarrays,out);
 
 
}
for (auto it = subarrays.begin(); it != subarrays.end();it++) {
  
       for (int i = 0; i < (*it).size(); i++) {
        cout << (*it)[i] << " ";
    }
    cout << endl;
    }
cout<<subarrays.size();
	return 0;
}
