#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	int ans=INT_MAX;
	int curr=0;
	for(int i=0;i<n;i++){
	curr+=arr[i];
	ans=min(ans,curr);
	}
	if(curr<0){
	cout<<-1*ans+1<<endl;
	}
	else{
	cout<<1<<endl;
	}
	return 0;
}