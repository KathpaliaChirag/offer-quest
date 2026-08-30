#include<bits/stdc++.h>
using namespace std;
int solve(string wall, int k,int n,char c){
	
	int mx=1;
	//count is used to store the non c character freq
	int count=0;
	int l=0;
	int r=0;
	while(r<n){
		if(wall[r]!=c){
			count++;
		}
		//if freq more than k start sliding the window by l and reducing the count
		while(count>k){
			if(wall[l]!=c) count--;
			l++;
		}
		mx=max(mx,r-l+1);
		r++;
	}
	return mx;


}
int answer(string wall,int k){
	int n=wall.size();
	int ans=1;
	for(int i=0;i<26;i++)
	{
	ans=max(ans,solve(wall,k,n,i+'a'));
	}
	return ans;
}
int main(){
	string wall;
	cin>>wall;
	int k;
	cin>>k;
	cout<<answer(wall,k)<<endl;

	return 0;
}