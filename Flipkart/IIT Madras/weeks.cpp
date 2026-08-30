#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> & pro){
	//sort(pro.begin(),pro.end());
	int sum=0;
	int n=pro.size();
	int mx=0;
	int ans=0;
	for(int i=0;i<n;i++){
	sum+=pro[i];
	mx=max(pro[i],mx);
	}
	if(mx-1<=(sum-mx)){
		ans+=sum;
	}
	else{
		ans+=(2*(sum-mx)+1);
	}
	return ans;
}
int main(){
	
	vector<int> proj1 = {11,4,5};//expected 19
	vector<int> proj2 = {5}; // expected 1
	vector<int> proj3 = {7,6,5,4,3,2,1};	// expected 28
	vector<int> proj4 = {3, 3}; //expected 6
	cout<<solve(proj1)<<endl;
	cout<<solve(proj2)<<endl;
	cout<<solve(proj3)<<endl;
	cout<<solve(proj4)<<endl;

	return 0;
}