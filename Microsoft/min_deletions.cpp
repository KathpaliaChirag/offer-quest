#include<bits/stdc++.h>
using namespace std;
 int solve(string s) {
       //Remove all occurences of yx
        stack<char> st;
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!st.empty() and st.top()=='y' and s[i]=='x'){
                count++;
                st.pop();
            }
            else{
                st.push(s[i]);
}
        }
        return count;
int main(){
	string s;
	cin>>s;
	cout<<solve(s)<<endl;
	return 0;
}